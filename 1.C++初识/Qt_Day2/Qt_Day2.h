#pragma once

#include <QtWidgets/QDialog>
#include "ui_Qt_Day2.h"

class Qt_Day2 : public QDialog
{
    Q_OBJECT

public:
    Qt_Day2(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_Day2Class ui;
};
