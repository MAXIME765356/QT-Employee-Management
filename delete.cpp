#include "delete.h"
#include "ui_delete.h"
#include "mainwindow.h"

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    MainWindow  conn;
    // condition -> to check if the connection with the database
    if(!conn.connectionOpen())
        ui->delconnection->setText("Database Disconnected ...");
    else
        ui->delconnection->setText("Database Connected ...");


}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_Back_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();

}




void Delete::on_DelButton_clicked()
{
     MainWindow  conn;

     QString Name,Address,Department;

     Name = ui->lineEdit_name->text();

     if(!conn.connectionOpen()){
             qDebug()<<"Failed to connect to database delete";
             return; }

     conn.connectionOpen();
     QSqlQuery Qry;
     Qry.prepare("DELETE FROM Employee WHERE NAME='"+Name+"'");

     if(Qry.exec()){
         QMessageBox::information(this,tr("DELETE"),tr("Information Deleted !"));
         conn.connectionClose();
         }
     else {
         QMessageBox::critical(this,tr("ERROR..."),Qry.lastError().text());
}

}
