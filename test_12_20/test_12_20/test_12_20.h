#pragma once

#include <QtWidgets/QWidget>
#include "ui_test_12_20.h"

class test_12_20 : public QWidget
{
    Q_OBJECT

public:
    test_12_20(QWidget *parent = Q_NULLPTR);

private:
    Ui::test_12_20Class ui;
};
