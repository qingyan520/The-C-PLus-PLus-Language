#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_QMainWindow.h"

class Qt_QMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Qt_QMainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_QMainWindowClass ui;
};
