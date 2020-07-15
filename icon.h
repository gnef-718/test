#ifndef ICON_H
#define ICON_H

#include <QPushButton>
#include<QPixmap>

class Icon : public QPushButton
{
    Q_OBJECT
public:
    int x,y;
    int type,flag;
    Icon(QWidget *parent = Q_NULLPTR,int x=200,int y=200,int type=0,int flag=0);
    void draw(int type=0);
    void draw2(int type=0);



signals:


};

#endif // ICON_H
