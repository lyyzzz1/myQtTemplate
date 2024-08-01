#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qlogging.h>
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , girl_(new girlFriend)
    , me_(new Me)
{
    void (girlFriend::*hungry)() = &girlFriend::hungry; 
    void (girlFriend::*hungryWithMsg)(QString) = &girlFriend::hungry;
    void (Me::*Eat)() = &Me::eat;
    void (Me::*eatWithMsg)(QString) = &Me::eat;
    ui->setupUi(this);
    connect(ui->mybutton,&QPushButton::clicked,girl_,hungry);
    connect(ui->mybutton, &QPushButton::clicked, girl_,
            [this]() -> void { girl_->hungry(ui->food->toPlainText()); });
    connect(girl_,hungry,me_,Eat);
    connect(girl_,hungryWithMsg,me_,eatWithMsg);
}

Me::Me(QObject* parent):QObject(parent){}

void Me::eat()
{
    qDebug() << "I take you eat Default!";
}

void Me::eat(QString msg)
{
    qDebug() << "I take you eat" << msg << "!!!!!";
}

MainWindow::~MainWindow()
{
    delete ui;
}
