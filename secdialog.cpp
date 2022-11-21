#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"
#include <QDialog>



SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    MainWindow  conn;
    // condition -> to check if the connection with the database
    if(!conn.connectionOpen())
        ui->addconnection->setText("Database Disconnected ...");
    else
        ui->addconnection->setText("Database Connected ...");


}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_2_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}



void SecDialog::on_SaveButton_clicked()
{

     MainWindow  conn;

     int Phone;
     int Age;
     double Salary;
     QString Name,Address,Department;


     Name = ui->lineEdit_name->text();
     Age = ui->lineEdit_age->text().toInt();                                              // Input data is obtained here where it is defined the Data Type to them.
     Department = ui->lineEdit_dep->text();
     Salary = ui->lineEdit_salary->text().toInt();
     Address = ui->lineEdit_address->text();
     Phone = ui->lineEdit_phone->text().toInt();

     if(!conn.connectionOpen()){
             qDebug()<<"Failed to connect to database Submit";
             return; }

     conn.connectionOpen();                                         // Query is made to here to save input data to table
     QSqlQuery Qry;
     Qry.prepare("INSERT INTO Employee (Name,Age,Department,Salary,Address,Phone) VALUES (?,?,?,?,?,?)");
     Qry.addBindValue(Name);
     Qry.addBindValue(Age);
     Qry.addBindValue(Department);
     Qry.addBindValue(Salary);
     Qry.addBindValue(Address);
     Qry.addBindValue(Phone);

         if(Qry.exec()){                                                           // check fubnction to see if the application is working or ot
         QMessageBox::information(this,tr("SUBMIT"),tr("Entry successfully Submitted !"));
         conn.connectionClose();
         }
     else {
         QMessageBox::critical(this,tr("ERROR..."),Qry.lastError().text());
     }
}



