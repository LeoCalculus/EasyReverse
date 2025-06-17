#pragma once

#include <QMainWindow>
// first include necessary libs:
#ifdef Q_OS_WIN // this tells only on Windows machine we will try to include such headers otherwise ignore this section
#include <windows.h>
#include <winuser.h>
#endif

#include <iostream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// NOLINTNEXTLINE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    // NOLINTNEXTLINE
    void on_btnGetHandle_clicked();
    // NOLINTNEXTLINE
    void on_btnRead_clicked();
    // NOLINTNEXTLINE
    void on_btnWrite_clicked();

private:
    Ui::MainWindow *ui;
};

