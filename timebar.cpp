#include "timebar.h"
#include "ui_timebar.h"
#include<QTimer>

TimeBar::TimeBar(QWidget *parent,int time) :
    QWidget(parent),time(time),
    ui(new Ui::TimeBar)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->progressBar->setStyleSheet("QProgressBar{background:rgb(255,240,245);} QProgressBar::chunk{border-radius:5px;background:rgb(255,182,193)}");

    num=time;
    timer=new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,[=](){
        ui->Timebox->display(num);
    });
    connect(timer,&QTimer::timeout,[=](){
        ui->progressBar->setValue(num);
        num--;
    });
}

TimeBar::~TimeBar()
{
    delete ui;
}

void TimeBar::plus()
{
    ui->Timebox->display(num);
    ui->progressBar->setValue(num);
}
