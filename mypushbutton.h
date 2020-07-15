#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QString>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    myPushButton(QString Img,QString pressImg="");
    QString ImgPath,pressImgPath;
   void jumpdown();
   void jumpup();

signals:

};

#endif // MYPUSHBUTTON_H
