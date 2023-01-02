#include "headers/addemp.h"
#include "ui_addemp.h"
#include "headers/mainwindow.h"
#include "QVBoxLayout"
#include "QPushButton"
#include <QSqlQuery>
#include <QMessageBox>
#include <QStringList>
#include <QDate>


AddEmp::AddEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmp)
{
    ui->setupUi(this);


    MainWindow  conn;
        setWindowTitle("ADD EMPLOYEE");



        // condition -> to check if the connection with the database
        if(!conn.dbUtils.connectionOpen())
            ui->addconnection->setText("Database Disconnected ...");
        else
            ui->addconnection->setText("Database Connected ...");

        ui->dateEdit->setCalendarPopup(true);
        ui->Edep->addItem("Marketing");
        ui->Edep->addItem("Sales");
        ui->Edep->addItem("Maintenance");
        ui->Edep->addItem("Stocks");


        ui->Egen->addItem("Male");
        ui->Egen->addItem("Female");


    }



AddEmp::~AddEmp()
{
    delete ui;
}




void AddEmp::on_SubButton_clicked()
{

    MainWindow  conn;
    int ID;
    double Salary;
    QString Phone, Name,Birth,Gender,Department;

    ID = ui->Eid->text().toInt();
    Name = ui->Ename->text();
    Department = ui->Edep->currentText();
    Gender = ui->Egen->currentText();
    Birth = ui->dateEdit->text();
    Phone = ui->Ephone->text();
    Salary = ui->Ejon->text().toInt();
                                            // Input data is obtained here where it is defined the Data Typ

    if(!conn.dbUtils.connectionOpen()){
            qDebug()<<"Failed to connect to database save";
            return; }

        conn.dbUtils.connectionOpen();                                         // Query is made to here to save input data to table
        QSqlQuery Qry;
        Qry.prepare("INSERT INTO Work (EmployeeID,NAME,DEPARTMENT,GENDER,BIRTH,PHONE,SALARY) VALUES (?,?,?,?,?,?,?)");
        Qry.addBindValue(ID);
        Qry.addBindValue(Name);
        Qry.addBindValue(Department);
        Qry.addBindValue(Gender);
        Qry.addBindValue(Birth);
        Qry.addBindValue(Phone);
        Qry.addBindValue(Salary);

            if(Qry.exec()){                                                           // check fubnction to see if the application is working or ot
            QMessageBox::information(this,tr("SAVE"),tr("Entry successfully saved !"));
            conn.dbUtils.connectionClose();
            }
        else {
            QMessageBox::critical(this,tr("ERROR..."),Qry.lastError().text());
        }
}


void AddEmp::on_BackButton_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}






void AddEmp::on_pushButton_clicked()
{

    ui->Eid->setText(getEmployeeID(getDepartmentShortName(ui->Edep)));


}







