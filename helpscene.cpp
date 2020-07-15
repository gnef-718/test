#include "helpscene.h"
#include"mypushbutton.h"
#include<QTimer>
#include<QPainter>
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>


HelpScene::HelpScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Help");
    this->setAttribute(Qt::WA_DeleteOnClose);

    myPushButton* backbtn=new myPushButton(":/image/icons8-back-100.png");
    backbtn->setParent(this);
    backbtn->move(0,0);

    connect(backbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();

        backbtn->jumpdown();
        backbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            emit back();
            delete clickplayer;
        });
    });
}

void HelpScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/helpbg.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
