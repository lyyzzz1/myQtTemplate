#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qicon.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}