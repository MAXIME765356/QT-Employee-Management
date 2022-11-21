#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#include "mainwindow.h"
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class employeeinfo;
}

class employeeinfo : public QDialog
{
    Q_OBJECT

public:
    explicit employeeinfo(QWidget *parent = nullptr);
    ~employeeinfo();

private slots:
    void on_BackButton_clicked();


    void on_Com_clicked();

private:
    Ui::employeeinfo *ui;
};

#endif // EMPLOYEEINFO_H
