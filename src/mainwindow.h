#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qobject.h>
#include <qtmetamacros.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class girlFriend;
class Me;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  girlFriend* girl_;
  Me* me_;
};

class girlFriend : public QObject {
  Q_OBJECT
public:
  explicit girlFriend(QObject *parent = nullptr) {}
signals:
  void hungry();
  void hungry(QString msg);
};

class Me : public QObject {
  Q_OBJECT
public:
  explicit Me(QObject *parent = nullptr);
public slots:
  void eat();
  void eat(QString msg);
};
#endif // MAINWINDOW_H
