#include "Qt_QMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_QMainWindow w;
    w.show();
    return a.exec();
}
