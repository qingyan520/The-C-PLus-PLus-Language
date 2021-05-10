#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_5_10.h"

class Qt_5_10 : public QMainWindow
{
    Q_OBJECT

public:
    Qt_5_10(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_5_10Class ui;
};
