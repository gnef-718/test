#include "mypushbutton.h"
#include<QPixmap>
#include<QPropertyAnimation>

 myPushButton::myPushButton(QString Img,QString pressImg)
 {
     ImgPath=Img;
     pressImgPath=pressImg;

     QPixmap pm;
     pm.load(Img);

     this->setFixedSize(pm.width(),pm.height());

     this->setStyleSheet("QPushButton{border:0px;}");

     this->setIcon(pm);

     this->setIconSize(QSize(pm.width(),pm.height()));
 }

 void myPushButton::jumpdown()
 {
     QPropertyAnimation * pa1=new QPropertyAnimation(this,"geometry");
     pa1->setDuration(250);
     pa1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
     pa1->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
     pa1->setEasingCurve(QEasingCurve::OutBounce);
     pa1->start();
 }


 void myPushButton::jumpup()
 {
     QPropertyAnimation * pa2=new QPropertyAnimation(this,"geometry");
     pa2->setDuration(250);
     pa2->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
     pa2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
     pa2->setEasingCurve(QEasingCurve::OutBounce);
     pa2->start();
 }
