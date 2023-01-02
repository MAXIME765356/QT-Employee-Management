#ifndef DELETE_H
#define DELETE_H

#include <QSqlError>
#include <QtSql>
#include <QDialog>


namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase Employ;


      void deleteEmployeeRecord(QString EmployeeID)
    {
        QSqlQuery *qry = new QSqlQuery(Employ);

        qry->prepare("DELETE  FROM Work WHERE EmployeeID='" + EmployeeID + "';");

        qry->exec();
    }



public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

   



private slots:
    void on_BackB_clicked();

    void on_Load_clicked();

    void on_DeltableView_doubleClicked(const QModelIndex &index);

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
