#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include "abstractview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public AbstractView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void SetController(AbstractController* controller_);
    ~MainWindow() override = default;

private slots:
    void on_pushButton_clicked() override;
private:
    void drawPinguin() override;
    Ui::MainWindow *ui;
    AbstractController* controller;
    bool add_button = 0;
};

#endif // MAINWINDOW_H
