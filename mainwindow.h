#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include "abstractview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    void newPinguin();
    Ui::MainWindow *ui;
    Controller controller;
    bool add_button = 0;
};

#endif // MAINWINDOW_H
