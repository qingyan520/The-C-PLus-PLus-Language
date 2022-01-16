#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //spinBox数字改变，slider跟着改变
    void(QSpinBox::*signal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,signal,ui->horizontalSlider,&QSlider::setValue);
    //slider改变，spinBox也改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}
void SmallWidget::setData(int val)
{
    ui->horizontalSlider->setValue(val);

}
int SmallWidget::getData()
{
    return ui->horizontalSlider->value();
}
SmallWidget::~SmallWidget()
{
    delete ui;
}
