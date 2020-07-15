#include "icon.h"
#include<QPainter>
#include<QPixmap>

Icon::Icon(QWidget *parent ,int x,int y,int type,int flag) :QPushButton(parent),x(x),y(y),type(type),flag(flag)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    QPixmap pix;
    switch(type)
    {
    case 1: pix.load(":/image/01.jpg");break;
    case 2: pix.load(":/image/02.jpg");break;
    case 3: pix.load(":/image/03.jpg");break;
    case 4: pix.load(":/image/04.jpg");break;
    case 5: pix.load(":/image/05.jpg");break;
    case 6: pix.load(":/image/06.jpg");break;
    case 7: pix.load(":/image/07.jpg");break;
    case 8: pix.load(":/image/08.jpg");break;
    case 9: pix.load(":/image/09.jpg");break;
    case 10: pix.load(":/image/10.jpg");break;
    case 11: pix.load(":/image/11.jpg");break;
    case 12: pix.load(":/image/12.jpg");break;
    case 13: pix.load(":/image/13.jpg");break;
    case 14: pix.load(":/image/14.jpg");break;
    case 15: pix.load(":/image/15.jpg");break;
    case 16: pix.load(":/image/16.jpg");break;
    }
    this->setFixedSize(80,80);

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width()*0.4,pix.height()*0.4));
}

void Icon::draw(int type)
{
    QPixmap pix;
    switch(type)
    {
    case 1: pix.load(":/image/01.jpg");break;
    case 2: pix.load(":/image/02.jpg");break;
    case 3: pix.load(":/image/03.jpg");break;
    case 4: pix.load(":/image/04.jpg");break;
    case 5: pix.load(":/image/05.jpg");break;
    case 6: pix.load(":/image/06.jpg");break;
    case 7: pix.load(":/image/07.jpg");break;
    case 8: pix.load(":/image/08.jpg");break;
    case 9: pix.load(":/image/09.jpg");break;
    case 10: pix.load(":/image/10.jpg");break;
    case 11: pix.load(":/image/11.jpg");break;
    case 12: pix.load(":/image/12.jpg");break;
    case 13: pix.load(":/image/13.jpg");break;
    case 14: pix.load(":/image/14.jpg");break;
    case 15: pix.load(":/image/15.jpg");break;
    case 16: pix.load(":/image/16.jpg");break;
    }
    this->setFixedSize(70,70);

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width()*0.4,pix.height()*0.4));
}

void Icon::draw2(int type)
{
    QPixmap pix2;
    switch(type)
    {
    case 1: pix2.load(":/image/p01.png");break;
    case 2: pix2.load(":/image/p02.png");break;
    case 3: pix2.load(":/image/p03.png");break;
    case 4: pix2.load(":/image/p04.png");break;
    case 5: pix2.load(":/image/p05.png");break;
    case 6: pix2.load(":/image/p06.png");break;
    case 7: pix2.load(":/image/p07.png");break;
    case 8: pix2.load(":/image/p08.png");break;
    case 9: pix2.load(":/image/p09.png");break;
    case 10: pix2.load(":/image/p10.png");break;
    case 11: pix2.load(":/image/p11.png");break;
    case 12: pix2.load(":/image/p12.png");break;
    case 13: pix2.load(":/image/p13.png");break;
    case 14: pix2.load(":/image/p14.png");break;
    case 15: pix2.load(":/image/p15.png");break;
    case 16: pix2.load(":/image/p16.png");break;
    }
    this->setFixedSize(70,70);

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix2);

    this->setIconSize(QSize(pix2.width()*0.4,pix2.height()*0.4));
}
