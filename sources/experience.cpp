#include "headers/experience.h"
#include "ui_experience.h"
#include "headers/mainwindow.h"
#include "headers/showexp.h"
#include "headers/exp.h"


Experience::Experience(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Experience)
{
    ui->setupUi(this);
}

Experience::~Experience()
{
    delete ui;
}

void Experience::on_Home_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}



void Experience::on_ShowExp_clicked()
{
  hide();
  ShowExp showexp;
  showexp.setModal(true);
  showexp.exec();

}


void Experience::on_AddExp_clicked()
{
    hide();
    Exp ex;
    ex.setModal(true);
    ex.exec();
}

