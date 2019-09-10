#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "view.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Controller stack_controller;

    View view;
    Controller controller;

    controller.SetView(&view);

    return a.exec();
}
