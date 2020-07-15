#include "pausescene.h"
#include<QPainter>
#include"mypushbutton.h"
#include"timebar.h"
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>

PauseScene::PauseScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Pause");
    this->setAttribute(Qt::WA_DeleteOnClose);

    myPushButton* btn=new myPushButton(":/image/icons8-pause-100.png");
    btn->setParent(this);
    btn->move(1100,0);

    connect(btn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        btn->jumpdown();
        btn->jumpup();

        QTimer::singleShot(300,this,[=](){
            emit goon();
            delete clickplayer;
        });
    });
}

void PauseScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/pause.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
