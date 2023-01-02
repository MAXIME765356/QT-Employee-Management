#include "headers/search.h"
#include "ui_search.h"
#include "headers/mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{


    ui->setupUi(this);

    setWindowTitle("SEARCH EMPLOYEE");

    MainWindow conn;

    ui->SearchtableView->setStyleSheet("alternate-background-color: #E4E4E4;background-color:white;selection-background-color:#1492E6;selection-color:white;");
    ui->SearchtableView->setAlternatingRowColors(true);


}



Search::~Search()
{
    delete ui;
}



void Search::on_Close_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();


}





void Search::on_loadButton_clicked()
{

    MainWindow conn;
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.dbUtils.connectionOpen();
    QSqlQuery* Qry = new QSqlQuery(conn.Employ);
    Qry->prepare("select * from Work");
    Qry->exec();
    modal->setQuery(*Qry);
    ui->SearchtableView->setModel(modal);
    qDebug() << (modal->rowCount());


}

