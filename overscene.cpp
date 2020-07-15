#include "overscene.h"
#include"mypushbutton.h"
#include<QTimer>
#include<QPainter>
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>


OverScene::OverScene(QWidget *parent,int flag) : QMainWindow(parent),flag(flag)
{
    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Over");
    this->setAttribute(Qt::WA_DeleteOnClose);

    myPushButton* restartbtn=new myPushButton(":/image/icons8-reset-100.png");
    myPushButton* choosebtn=new myPushButton(":/image/icons8-back-100.png");

    restartbtn->setParent(this);
    choosebtn->setParent(this);

    restartbtn->move(400-restartbtn->width(),this->height()*0.6);
    choosebtn->move(800-choosebtn->width(),this->height()*0.6);

    connect(restartbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();

        restartbtn->jumpdown();
        restartbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
           emit restart();
        });
    });

    connect(choosebtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();

        choosebtn->jumpdown();
        choosebtn->jumpup();
        QTimer::singleShot(400,this,[=](){
           emit choose();
        });
    });
}

void OverScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    if(flag==0)
    pix.load(":/image/win.jpg");
    else
    pix.load(":/image/lose.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
