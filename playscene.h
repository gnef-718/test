#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"icon.h"
#include"ctime"
#include"timebar.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr,int level=1);
    void paintEvent(QPaintEvent *event);
    Icon ic[12][10];
    void datarandom();
    int level,row,col,patternum,limit,limit2,di;
    void initialize();
    void process();
    int hintx1,hintx2,hinty1,hinty2,x1,x2,y1,y2;
    bool Zero(int a1, int a2, int b1, int b2);
    bool One(int a1, int a2, int b1, int b2);
    bool Two(int a1, int a2, int b1, int b2);
    bool Judge(int a1, int a2, int b1, int b2);
    bool reshuffle();
    int min(int a, int b);
    int max(int a, int b);
    TimeBar* tb;
    bool clear();
    void change();

signals:
    void home();
    void back();
    void musicstop();
    void musicplay();
    void reshuffletrue();


};

#endif // PLAYSCENE_H
