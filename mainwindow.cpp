#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include "update.h"
#include "employeeinfo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delete.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // Function call from header file
    // condition -> to check if the connection with the database
    if(!connectionOpen())
        ui->connectionLabel->setText("Database Disconnected ....");
    else
        ui->connectionLabel->setText("Database Connected .......");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddButton_clicked()
{
   hide();
   SecDialog  secdialog;
   secdialog.setModal(true);
   secdialog.exec();


}

void MainWindow::on_UpdateButton_clicked()
{
    hide();
    Update update;
    update.setModal(true);
    update.exec();
}



void MainWindow::on_InFoButton_clicked()
{
    hide();
    employeeinfo empinfo;
    empinfo.setModal(true);
    empinfo.exec();


}


void MainWindow::on_DeleteButton_clicked()
{
    hide();
    Delete del;
    del.setModal(true);
    del.exec();


}

