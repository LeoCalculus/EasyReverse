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
HWND gameWindowHandle = 0;
DWORD gameProcessID = 0;
HANDLE gameHandle = 0;
// last read value as global variable
int readValueInt = 0;
float readValueFloat = 0.0;
double readValueDouble = 0.0;
int readValuePtr = 0; // this will be base 16

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
    QWidget::setWindowTitle("Easy Reverse");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnGetHandle_clicked()
{
    // HWND is a handle to a window
    HWND myHandle = reinterpret_cast<HWND>(this->winId()); // HWND for handle
    // we are running in cmd condition, so we call powershell and use command to find the process and return the window name
    // get the name string first
    std::string gameName = ui->txtGameName->text().toStdString();
    std::string command = "powershell -noprofile -command \"Get-Process | Where-Object { $_.MainWindowTitle -Like '*" + gameName + "*' } | Select-Object -ExpandProperty MainWindowTitle\"";
    std::string resultTarget = exec(command.c_str());
    // remove all the \n\r\t which might influence the search for window
    size_t endstrings = resultTarget.find_last_not_of(" \n\r\t"); // find_last_not_of has internal loop and find the first one not included in the bracket
    if( std::string::npos != endstrings ) {
        resultTarget = resultTarget.substr( 0, endstrings + 1 );
    }

    std::cout << resultTarget << std::endl;

    // casting to LPCSTR according to doc
    LPCSTR gameProcess = resultTarget.c_str();
    HWND target = FindWindowA(NULL, gameProcess);
    if (target == NULL) {
        QWidget::setWindowTitle("Easy Reverse : Error");
        MessageBoxW(myHandle, L"Error! Could not find the process handle!", L"Error", MB_OK | MB_ICONERROR);
        return;
    }

    // when we got the handle, we can open process:
    // note the DWORD is a 32 bit unsigned integer used to store the process ID
    DWORD processID;
    GetWindowThreadProcessId(target, &processID);
    // check valid:
    if (processID == 0) {
        MessageBoxW(myHandle, L"Error! Invalid process ID!", L"Error", MB_OK | MB_ICONERROR);
        return;
    }

    // now we can have handle to kernel objects:
    HANDLE gameKernelProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    // check:
    if (gameKernelProcess == NULL) {
        MessageBoxW(myHandle, L"Error! Invalid handle to kernel objects!", L"Error", MB_OK | MB_ICONERROR);
        return;
    }
    // if we can reach here, it means we get the correct process, update window for info
    QString updateName = QString::fromStdString(resultTarget);
    QWidget::setWindowTitle("Selected: "+ updateName);
    // store all necessary things in global varibles:
    gameWindowHandle = target;
    gameProcessID = processID;
    gameHandle = gameKernelProcess;
}



void MainWindow::on_btnRead_clicked()
{
    // first check handle state:
    if (gameProcessID == 0) {
        return; // doing nothing since we did not initialize
    }
    // otherwise start reading and write value:
    // first get the address from the box:
    QString readAddressString = ui->txtInputAddress->text();
    QString showValue;
    bool conversion = 0;
    uintptr_t targetAddress = readAddressString.toULongLong(&conversion, 16); // return in unsigned long long with base 16!
    LPCVOID targetReadingAddress = (LPCVOID)targetAddress;
    switch (ui->boxDataType->currentIndex()) {
        case 0: // this is int
            ReadProcessMemory(gameHandle, targetReadingAddress, &readValueInt, sizeof(readValueInt), NULL);
            showValue = QString::number(readValueInt);
            break;
        case 1:
            ReadProcessMemory(gameHandle, targetReadingAddress, &readValueFloat, sizeof(readValueFloat), NULL);
            showValue = QString::number(readValueFloat);
            break;
        case 2:
            ReadProcessMemory(gameHandle, targetReadingAddress, &readValueDouble, sizeof(readValueDouble), NULL);
            showValue = QString::number(readValueDouble);
            break;
        case 3:
            ReadProcessMemory(gameHandle, targetReadingAddress, &readValuePtr, sizeof(readValuePtr), NULL);
            showValue = QString::number(readValuePtr, 16); // with base 16
            break;
        default:
            ReadProcessMemory(gameHandle, targetReadingAddress, &readValueInt, sizeof(readValueInt), NULL);
            showValue = QString::number(readValueInt);
            break;
    }

    ui->txtOutput->setText(showValue);
}


void MainWindow::on_btnWrite_clicked()
{
    if (gameProcessID == 0) {
        return; // doing nothing since we did not initialize
    }
    QString writeAddressString = ui->txtInputAddress->text();
    bool conversion = 0;
    uintptr_t targetAddress = writeAddressString.toULongLong(&conversion, 16); // return in unsigned long long with base 16!
    LPVOID targetWrittingAddress = (LPVOID)targetAddress;
    int writeValueInt = ui->txtOutput->text().toInt();
    WriteProcessMemory(gameHandle, targetWrittingAddress, &writeValueInt, sizeof(writeValueInt), NULL);
    QString showValue = QString::number(writeValueInt);
    ui->txtOutput->setText(showValue);
}

