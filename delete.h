#ifndef DELETE_H
#define DELETE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"

namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

private slots:
    void on_Back_clicked();

    void on_DelButton_clicked();


private:
    Ui::Delete *ui;
};

#endif // DELETE_H
