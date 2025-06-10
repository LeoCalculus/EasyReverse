#include "mainwindow.h"
#include "ui_mainwindow.h"

// first include necessary libs:
#ifdef Q_OS_WIN // this tells only on windows machine we will try to include such headers otherwise ignore this section
#include <windows.h>
#include <winuser.h>
#endif

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

// global variables
HWND terraWindowHandle = 0;
DWORD terraProcessID = 0;
HANDLE terraHandle = 0;


// function used to get the output from the commands
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGetHandle_clicked()
{
    // we are running in cmd condition, so we call powershell and use command to find the process and return the window name
    std::string resultTarget = exec("powershell -noprofile -command \"Get-Process | Where-Object { $_.MainWindowTitle -Like '*Terra*' } | Select-Object -ExpandProperty MainWindowTitle\"");
    // remove all the \n\r\t which might influence the search for window
    size_t endstrings = resultTarget.find_last_not_of(" \n\r\t"); // find_last_not_of has internal loop and find the first one not included in the bracket
    if( std::string::npos != endstrings ) {
        resultTarget = resultTarget.substr( 0, endstrings + 1 );
    }
    std::cout << resultTarget << std::endl;
    // casting to LPCSTR according to doc
    LPCSTR terraProcess = resultTarget.c_str();
    // HWND is a handle to a window
    HWND myHandle = reinterpret_cast<HWND>(this->winId()); // HWND for handle
    HWND target = FindWindowA(NULL, terraProcess);
    if (target == NULL) {
        MessageBoxW(myHandle, L"Error! Could not find the process handle!", L"Error", MB_OK | MB_ICONERROR);
    }

    // when we got the handle, we can open process:
    // note the DWORD is a 32 bit unsigned integer used to store the process ID
    DWORD processID;
    GetWindowThreadProcessId(target, &processID);
    // check valid:
    if (processID == 0) {
        MessageBoxW(myHandle, L"Error! Invalid process ID!", L"Error", MB_OK | MB_ICONERROR);
    }

    // now we can have handle to kernel objects:
    HANDLE terrariaProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    // check:
    if (terrariaProcess == NULL) {
        MessageBoxW(myHandle, L"Error! Invalid handle to kernel objects!", L"Error", MB_OK | MB_ICONERROR);
    }
    // store all necessary things in global varibles:
    terraWindowHandle = target;
    terraProcessID = processID;
    terraHandle = terrariaProcess;
}



void MainWindow::on_btnRead_clicked()
{
    // first check handle state:
    if (terraProcessID == 0) {
        return; // doing nothing since we did not initialize
    }
    // otherwise start reading and write value:
    // first get the address from the box:
    QString readAddressString = ui->txtInputAddress->text();
    bool conversion = 0;
    uintptr_t targetAddress = readAddressString.toULongLong(&conversion, 16); // return in unsigned long long with base 16!
    LPCVOID targetReadingAddress = (LPCVOID)targetAddress;
    int readValueInt = 0;
    ReadProcessMemory(terraHandle, targetReadingAddress, &readValueInt, sizeof(readValueInt), NULL);
    QString showValue = QString::number(readValueInt);
    ui->txtOutput->setText(showValue);
}


void MainWindow::on_btnWrite_clicked()
{
    if (terraProcessID == 0) {
        return; // doing nothing since we did not initialize
    }
    QString writeAddressString = ui->txtInputAddress->text();
    bool conversion = 0;
    uintptr_t targetAddress = writeAddressString.toULongLong(&conversion, 16); // return in unsigned long long with base 16!
    LPVOID targetWrittingAddress = (LPVOID)targetAddress;
    int writeValueInt = ui->txtOutput->text().toInt();
    WriteProcessMemory(terraHandle, targetWrittingAddress, &writeValueInt, sizeof(writeValueInt), NULL);
    QString showValue = QString::number(writeValueInt);
    ui->txtOutput->setText(showValue);
}

