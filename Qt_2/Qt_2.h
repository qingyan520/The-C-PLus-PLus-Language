#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_2.h"
#include"Teacher.h"
#include"student.h"

class Qt_2 : public QMainWindow
{
    Q_OBJECT

public:
    Qt_2(QWidget *parent = Q_NULLPTR);
    Teacher* zt;
    student* st;
    void classisover();
private:
    Ui::Qt_2Class ui;
};
