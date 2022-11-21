#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include "mainwindow.h"

employeeinfo::employeeinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employeeinfo)
{
    ui->setupUi(this);

    MainWindow  conn;
    // condition -> to check if the connection with the database
    if(!conn.connectionOpen())
        ui->loadconnection->setText("Database Disconnected ...");
    else
        ui->loadconnection->setText("Database Connected ...");


}

employeeinfo::~employeeinfo()
{
    delete ui;
}

void employeeinfo::on_BackButton_clicked()
{

    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}



void employeeinfo::on_Com_clicked()
{
    MainWindow  conn;
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connectionOpen();
    QSqlQuery* Qry = new QSqlQuery(conn.database);
    Qry->prepare("select * from Employee");
    Qry->exec();
    modal->setQuery(*Qry);
    ui->load_tableView->setModel(modal);
    qDebug() << (modal->rowCount());



}

