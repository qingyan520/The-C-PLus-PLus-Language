#include "Qt_QMainWindow.h"
#include<qmenubar.h>
Qt_QMainWindow::Qt_QMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* bar = menuBar();
    this->setMenuBar(bar);
    QMenu* fildmenu = bar->addMenu("нд╪Ч");
    ui.setupUi(this);
}
