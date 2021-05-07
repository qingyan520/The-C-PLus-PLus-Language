#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_1.h"

class Qt_1 : public QMainWindow
{
    Q_OBJECT

public:
    Qt_1(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_1Class ui;
};
