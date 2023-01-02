#ifndef ADDEMP_H
#define ADDEMP_H


#include <QDialog>
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
#define NOM_BD QString("Employ.db")


namespace Ui {
class AddEmp;
}

class AddEmp : public QDialog
{
    Q_OBJECT
    


public:
    explicit AddEmp(QWidget *parent = nullptr);
    ~AddEmp();



    

public:
    QSqlDatabase Employ;
 QString getLastID()
    {
        QSqlQuery *qry = new QSqlQuery(Employ);

        qry->prepare("SELECT MAX(EmployeeID) FROM Work");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt() + 1;

        return QString::number(lastID);
    }

    QString getTotalDept()
    {
        QSqlQuery *qry = new QSqlQuery(Employ);

        qry->prepare("SELECT COUNT(DISTINCT(department)) FROM company");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt();

        return QString::number(lastID);
    }

    QString getEmployeeID(QString )
    {
        return  getLastID();
    }

    QString getDepartmentShortName(QComboBox* Edep)
    {
        QSqlQuery *qry = new QSqlQuery(Employ);

        qry->prepare("SELECT * FROM Department WHERE Name='" + Edep->currentText() + "';");
        qry->exec();
        qry->next();

        QString x = qry->value(0).toString();

        return x;
    }

  


private slots:
    void on_SubButton_clicked();

    void on_BackButton_clicked();

    void on_pushButton_clicked();


private:
    Ui::AddEmp *ui;
};

#endif // ADDEMP_H
