#include "mainwindow.h"
#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Controller controller(&w);

    w.SetController(&controller);
    return a.exec();
}
