#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMainWindow>
#include <QtSql>                                // For using the SQL database
#include <QDebug>                               // For using the qDebug function
#include <QFileInfo>                            // For using the function to access the path and database file
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase database;
    // employeeData -> name of the database file where data from here is stored

    void connectionClose()
    // function to close the connection with the database
    {
        database.close();
        database.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    // function to open the connection to the database
    {
        database = QSqlDatabase::addDatabase("QSQLITE");                        // add the database into the project
        database.setHostName("localhost");
        database.setDatabaseName("C:/Users/pc/Desktop/Database/database.db");   // sets the database name in the file destintaion

        //Condition  -> for the messages to print when the onnection is made with the database
        if(!database.open()){
            qDebug()<<("Database Disconnected ...");
            return false;
        }
        else {
            qDebug()<<("Database Connected ...");
            return true;
        }
        }

public:

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:


    void on_AddButton_clicked();



    void on_UpdateButton_clicked();



    void on_InFoButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
