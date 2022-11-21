#include "update.h"
#include "ui_update.h"
#include "mainwindow.h"

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);


    MainWindow  conn;
    // condition -> to check if the connection with the database
    if(!conn.connectionOpen())
        ui->upconnection->setText("Database Disconnected ...");
    else
        ui->upconnection->setText("Database Connected ...");



}

Update::~Update()
{
    delete ui;
}



void Update::on_BackButton_clicked()
{

    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();

}



void Update::on_Update_2_clicked()
{
     MainWindow  conn;

     QString Name,Address,Department;

     if(!conn.connectionOpen()){
             qDebug()<<"Failed to connect to database update";
             return; }
                                                                           // update query is made here
     conn.connectionOpen();
     QSqlQuery Qry;
     Qry.prepare("UPDATE Employee SET NAME=:Name, AGE=:Age, DEPARTMENT=:Department, SALARY=:Salary,ADDRESS=:Address,PHONE=:Phone, WHERE EmployeeID=:ID");


     Qry.bindValue(":ID",ui->lineEdit_name->text());



     if(Qry.exec()){
         QMessageBox::information(this,tr("EDIT"),tr("Updated successfully !"));
         conn.connectionClose();
         }
     else {
         QMessageBox::critical(this,tr("ERROR..."),Qry.lastError().text());
     }

}

