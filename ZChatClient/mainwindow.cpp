#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->_loginDialog = new LoginDialog();
    setCentralWidget(_loginDialog);
    _loginDialog->show();

    this->_registerDialog = new RegisterDialog();
    connect(this->_loginDialog, &LoginDialog::unregistered, this, &MainWindow::showRegisterDialog);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(this->_loginDialog){
        delete _loginDialog;
        _loginDialog = nullptr;
    }
    if(this->_registerDialog){
        delete  _registerDialog;
        _registerDialog = nullptr;
    }
}

void MainWindow::showRegisterDialog()
{
    setCentralWidget(this->_registerDialog);
    this->_loginDialog->hide();
    this->_registerDialog->show();
}
