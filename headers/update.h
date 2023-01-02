#ifndef UPDATE_H
#define UPDATE_H


#include <QDialog>
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
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QLabel>
#include <QTableView>
#include <QSqlDatabase>


namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT


public:
     QSqlDatabase Employ;

     void setEmployeeUpdateDetails(QTableView* UptableView)
    {
        if(Employ.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT EmployeeID, NAME FROM Work;");
            UptableView->setModel(querModel);
        }
    }

    QSqlQuery* showEmployeeDetailsToLineEdit(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(Employ);

        qry->prepare("SELECT * FROM Work WHERE EmployeeID='" + id + "';");
        qry->exec();
        qry->next();

        return qry;
    }
     
    


public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();



    void connectToDataBase();

private slots:
    void on_Back_clicked();



    void on_UpButton_clicked();

    void on_Ref_clicked();


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_UptableView_activated(const QModelIndex &index);

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
