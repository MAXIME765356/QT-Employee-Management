#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define NOM_BD QString("Employ.db")
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QMainWindow>
#include <QtSql>                                // For using the SQL database
#include <QDebug>                               // For using the qDebug function
#include <QFileInfo>                            // For using the function to access the path and database file
#include <QMessageBox>
#include <QString>
#include <QtSql>
#include <QStandardPaths>
#include <QDir>
#include <QVariantMap>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include  <sources/database.cpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    QSqlDatabase Employ;
    // employeeData -> name of the database file where data from here is stored


 

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Database dbUtils;
    
       


private slots:





    void on_UpButton_clicked();

    void on_SearchButton_clicked();

    void on_DelButton_clicked();

    void on_AddButton_clicked();

    void on_Exp_clicked();

    void on_Seach_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
