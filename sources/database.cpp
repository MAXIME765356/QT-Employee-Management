#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QLabel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>        

class Database
{
    public:
          QSqlDatabase Employ;

  
    void connectionClose()
    // function to close the connection with the database
    {
        Employ.close();
        Employ.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    // function to open the connection to the database
    {

   Employ = QSqlDatabase::addDatabase("QSQLITE");                        // add the database into the pro
   Employ.setHostName("localhost");
   Employ.setDatabaseName("C:/Users/pc/Desktop/Personnell_Management-master/Employ.db");   // sets the database name in the file destintaion

        //Condition  -> for the messages to print when the onnection is made with the database
        if(!Employ.open()){
            qDebug()<<("Database Disconnected ...");
            return false;
        }
        else {
            qDebug()<<("Database Connected ...");
            return true;

        }
        }
};






