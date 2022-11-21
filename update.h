#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT





public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();

private slots:

    void on_BackButton_clicked();



    void on_Update_2_clicked();

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
