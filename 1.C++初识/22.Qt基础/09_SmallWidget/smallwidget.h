#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);
    ~SmallWidget();

    //设置数据
    void setData(int val);

    //获取数据
    int getData();

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
