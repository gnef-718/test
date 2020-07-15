#ifndef TIMEBAR_H
#define TIMEBAR_H

#include <QWidget>
#include<QTimer>

namespace Ui {
class TimeBar;
}

class TimeBar : public QWidget
{
    Q_OBJECT

public:
    explicit TimeBar(QWidget *parent = nullptr,int time=100);
    ~TimeBar();
    int time,num;
    QTimer* timer;
    void plus();

private:

    Ui::TimeBar *ui;
};

#endif // TIMEBAR_H
