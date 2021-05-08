#include "Qt_2.h"
#include <QtWidgets/QApplication>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_2 w;
    w.show();
    return a.exec();
}
