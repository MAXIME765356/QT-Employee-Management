#ifndef SEARCH_H
#define SEARCH_H

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

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT



public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();



private slots:
    void on_Close_clicked();



    void on_loadButton_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
