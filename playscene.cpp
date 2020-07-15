#include "playscene.h"
#include"mypushbutton.h"
#include"helpscene.h"
#include<QTimer>
#include"overscene.h"
#include<QPainter>
#include"icon.h"
#include"ctime"
#include<QDebug>
#include<stdlib.h>
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include"timebar.h"
#include"pausescene.h"


PlayScene::PlayScene(QWidget *parent,int level) : QMainWindow(parent),level(level)
{
    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Game");
    this->setAttribute(Qt::WA_DeleteOnClose);

    x1=0,x2=0,y1=0,y2=0;

    HelpScene* hs=new HelpScene(this);
    PauseScene* pas=new PauseScene(this);
    OverScene* os1=new OverScene(this);
    OverScene* os2=new OverScene(this,1);
    tb=new TimeBar(this,100);
    tb->move(1000,135);

    QTimer* timer=new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,[=](){
        if(tb->num==0)
        {
            this->hide();
            os2->show();
            QMediaPlayer* loseplayer = new QMediaPlayer;
            loseplayer->setMedia(QUrl("E:/Qt/LinkGame/image/gameover.wav"));
            loseplayer->play();
            QTimer::singleShot(6000,this,[=](){
                delete loseplayer;
            });

        }
    });

    switch (level)
        {
    case 1: row = 6; col = 5; patternum = 5; limit=6;limit2=6;di=5;break;
    case 2: row = 7; col = 6; patternum = 7; limit= 6;limit2=6;di=7;break;
    case 3: row = 8; col = 6; patternum = 8; limit= 6;limit2=6;di=8;break;
    case 4: row = 9; col = 6; patternum = 9;limit= 6;limit2=6; di=9;break;
    case 5: row = 10; col = 8; patternum = 10;limit= 8; limit2=8;di=10;break;
    case 6: row = 10; col = 8; patternum = 14; limit= 6;limit2=2;di=13;break;
    case 7: row = 10; col = 8; patternum = 14; limit= 6;limit2=2;di=13;break;
    case 8: row = 10; col = 8; patternum = 15; limit= 6;limit2=4;di=10;break;
    case 9: row = 10; col = 8; patternum = 16; limit= 6;limit2=4;di=8;break;
        }

    for (int i = 6-row/2; i < 6-row/2+row; i++)
        for (int j = 5-col/2; j < 5-col/2+col; j++)
            ic[i][j].flag=1;

    datarandom();

    for(int i=0;i<12;i++)
        for(int j=0;j<10;j++)
            ic[i][j].draw(ic[i][j].type);

    for(int i=0;i<12;i++)
        for(int j=0;j<10;j++)
        {
            ic[i][j].setParent(this);
            ic[i][j].x=i*(5+ic[i][j].width())+130;
            ic[i][j].y=j*(ic[i][j].height()+5)+160;
            ic[i][j].move(ic[i][j].x,ic[i][j].y);
        }

    if(reshuffle())
    {
        for (int i = 6-row/2; i < 6-row/2+row; i++)
            for (int j = 5-col/2; j < 5-col/2+col; j++)
                ic[i][j].flag=1;

        int pn[16]={},n=0;
        for (int i = 6-row/2; i < 6-row/2+row; i++)
        {
            for (int j = 5-col/2; j < 5-col/2+col; j++)
            {
                    static int seed=0;
                    static int s=10;
                    srand(seed+=(s++));
                    int t=(rand() % patternum) + 1;
                    pn[t-1]++;n++;
                    if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                    {
                         ic[i][j].type = t;
                    }
                    else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                    {
                        ic[i][j].type = t;
                    }
                    else
                    {
                        j--;
                        n--;
                    }
            }
        }

        for(int i=0;i<12;i++)
            for(int j=0;j<10;j++)
            {
                ic[i][j].draw(ic[i][j].type);
                ic[i][j].show();
            }

        x1=0,x2=0,y1=0,y2=0;
    }

    for(int i=0;i<12;i++)
        for(int j=0;j<10;j++)
            connect(&ic[i][j],&QPushButton::clicked,[=](){
                QMediaPlayer *clickplayer = new QMediaPlayer;
                clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
                clickplayer->play();
                QTimer::singleShot(1000,this,[=](){
                   delete clickplayer;
                });


                if(reshuffle())
                {
                    for (int i = 6-row/2; i < 6-row/2+row; i++)
                        for (int j = 5-col/2; j < 5-col/2+col; j++)
                            ic[i][j].flag=1;

                    int pn[16]={},n=0;
                    for (int i = 6-row/2; i < 6-row/2+row; i++)
                    {
                        for (int j = 5-col/2; j < 5-col/2+col; j++)
                        {
                                static int seed=0;
                                static int s=10;
                                srand(seed+=(s++));
                                int t=(rand() % patternum) + 1;
                                pn[t-1]++;n++;
                                if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                                {
                                     ic[i][j].type = t;
                                }
                                else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                                {
                                    ic[i][j].type = t;
                                }
                                else
                                {
                                    j--;
                                    n--;
                                }
                        }
                    }

                    for(int i=0;i<12;i++)
                        for(int j=0;j<10;j++)
                        {
                            ic[i][j].draw(ic[i][j].type);
                            ic[i][j].show();
                        }

                    x1=0,x2=0,y1=0,y2=0;
                }
                ic[x1][y1].draw(ic[x1][y1].type);
                x1=x2;
                y1=y2;
                x2=i;
                y2=j;
                ic[x2][y2].draw2(ic[x2][y2].type);

                process();
                if(clear())
                {
                    this->hide();
                    os1->show();
                    QMediaPlayer *succeedplayer = new QMediaPlayer;
                    succeedplayer->setMedia(QUrl("E:/Qt/LinkGame/image/succeed.wav"));
                    succeedplayer->play();
                    timer->stop();
                    QTimer::singleShot(6000,this,[=](){
                        delete succeedplayer;
                    });

                }
            });

    myPushButton* backbtn=new myPushButton(":/image/icons8-back-100.png");
    backbtn->setParent(this);
    backbtn->move(backbtn->width()-100,this->height()-backbtn->height()-5);

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

    myPushButton* homebtn=new myPushButton(":/image/icons8-home-page-100.png");
    homebtn->setParent(this);
    homebtn->move(0,0);
    connect(homebtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        homebtn->jumpdown();
        homebtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            emit home();
            delete clickplayer;
        });
    });


    myPushButton* hintbtn=new myPushButton(":/image/icons8-innovation-100.png");
    hintbtn->setParent(this);
    hintbtn->move(100,0);
    connect(hintbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        hintbtn->jumpdown();
        hintbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            reshuffle();
            ic[hintx1][hinty1].draw2(ic[hintx1][hinty1].type);
            ic[hintx2][hinty2].draw2(ic[hintx2][hinty2].type);
            delete clickplayer;
        });
    });


    myPushButton* musicbtn=new myPushButton(":/image/icons8-record-64.png");
    musicbtn->setParent(this);
    musicbtn->move(220,20);
    connect(musicbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        musicbtn->jumpdown();
        musicbtn->jumpup();
        static int musicnum=0;
        QTimer::singleShot(300,this,[=](){
            if(musicnum%2==0)
            {
                musicbtn->setIcon(QIcon(":/image/icons8-record-64 (1).png"));
                musicnum++;
                emit musicstop();
            }
            else
            {
                musicbtn->setIcon(QIcon(":/image/icons8-record-64.png"));
                musicnum++;
                emit musicplay();
            }
            delete clickplayer;
        });
    });

    myPushButton* helpbtn=new myPushButton(":/image/icons8-help-100.png");
    helpbtn->setParent(this);
    helpbtn->move(300,0);
    connect(helpbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        helpbtn->jumpdown();
        helpbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            this->hide();
            hs->show();
            delete clickplayer;
        });
    });

    myPushButton* pausebtn=new myPushButton(":/image/icons8-play-100.png");
    pausebtn->setParent(this);
    pausebtn->move(1100,0);

    connect(hs,&HelpScene::back,[=](){
        hs->hide();
        this->show();
    });
    connect(pausebtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();


        pausebtn->jumpdown();
        pausebtn->jumpup();

        QTimer::singleShot(300,this,[=](){
            tb->timer->stop();
            this->hide();
            pas->show();
            delete clickplayer;
        });
    });

    connect(os1,&OverScene::restart,[=](){
        os1->hide();
        this->show();

        for (int i = 6-row/2; i < 6-row/2+row; i++)
            for (int j = 5-col/2; j < 5-col/2+col; j++)
                ic[i][j].flag=1;

        int pn[16]={},n=0;
        for (int i = 6-row/2; i < 6-row/2+row; i++)
        {
            for (int j = 5-col/2; j < 5-col/2+col; j++)
            {
                    static int seed=0;
                    static int s=10;
                    srand(seed+=(s++));
                    int t=(rand() % patternum) + 1;
                    pn[t-1]++;n++;
                    if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                    {
                         ic[i][j].type = t;
                    }
                    else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                    {
                        ic[i][j].type = t;
                    }
                    else
                    {
                        j--;
                        n--;
                    }
            }
        }

        for(int i=0;i<12;i++)
            for(int j=0;j<10;j++)
            {
                ic[i][j].draw(ic[i][j].type);
                ic[i][j].show();
            }

        x1=0,x2=0,y1=0,y2=0;
        tb->num=100;
    });

    connect(os2,&OverScene::restart,[=](){
        os2->hide();
        this->show();

        for (int i = 6-row/2; i < 6-row/2+row; i++)
            for (int j = 5-col/2; j < 5-col/2+col; j++)
                ic[i][j].flag=1;

        int pn[16]={},n=0;
        for (int i = 6-row/2; i < 6-row/2+row; i++)
        {
            for (int j = 5-col/2; j < 5-col/2+col; j++)
            {
                    static int seed=0;
                    static int s=10;
                    srand(seed+=(s++));
                    int t=(rand() % patternum) + 1;
                    pn[t-1]++;n++;
                    if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                    {
                         ic[i][j].type = t;
                    }
                    else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                    {
                        ic[i][j].type = t;
                    }
                    else
                    {
                        j--;
                        n--;
                    }
            }
        }

        for(int i=0;i<12;i++)
            for(int j=0;j<10;j++)
            {
                ic[i][j].draw(ic[i][j].type);
                ic[i][j].show();
            }

        x1=0,x2=0,y1=0,y2=0;
        tb->num=100;
    });

    connect(pas,&PauseScene::goon,[=](){
        pas->hide();
        this->show();
        tb->timer->start();
    });



    connect(os1,&OverScene::choose,[=](){
        os1->hide();
        emit back();
    });

    connect(os2,&OverScene::choose,[=](){
        os2->hide();
        emit back();
    });

    connect(this,&PlayScene::reshuffletrue,[=](){
        if(reshuffle())
        {

            int pn[16]={},n=0;
            for (int i = 6-row/2; i < 6-row/2+row; i++)
            {
                for (int j = 5-col/2; j < 5-col/2+col; j++)
                {
                    static int seed=0;
                    static int s=10;
                    srand(seed+=(s++));
                    int t=(rand() % patternum) + 1;
                    if(ic[i][j].flag==0)continue;
                    pn[t-1]++;n++;
                    if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                    {
                         ic[i][j].type = t;
                    }
                    else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                    {
                        ic[i][j].type = t;
                    }
                    else
                    {
                        j--;
                        n--;
                    }
                }
            }
        }
    });
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/nbg2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void PlayScene::datarandom()
{
    int pn[16]={},n=0;
    for (int i = 6-row/2; i < 6-row/2+row; i++)
    {
        for (int j = 5-col/2; j < 5-col/2+col; j++)
        {
            if (ic[i][j].type== 0&&ic[i][j].flag==0)continue;
            else
            {
                static int seed=0;
                static int s=10;
                srand(seed+=(s++));
                int t=(rand() % patternum) + 1;
                pn[t-1]++;n++;
                if(pn[t-1]<=limit&&n<=row*col&&t<=di)
                {
                     ic[i][j].type = t;
                }
                else if(pn[t-1]<=limit2&&n<=row*col&&t>di)
                {
                    ic[i][j].type = t;
                }
                else
                {
                    j--;
                    n--;
                }
            }
        }
    }
}

void PlayScene::initialize()
{
    datarandom();
    for(int i=0;i<12;i++)
        for(int j=0;j<10;j++)
            ic[i][j].draw(ic[i][j].type);
}

bool PlayScene::Zero(int a1, int a2, int b1, int b2)
{
    int flag = 0;
        if(a1 == b1 && a2 == b2)
            return false;
        if(a1 == b1)
        {
            flag = 1;
            for(int i = min(a2,b2)+1; i < max(a2,b2); i++)
                if(ic[a1][i].flag != 0)
                    flag=0;
        }
        if(a2 == b2)
        {
            flag = 1;
            for(int i = min(a1,b1)+1; i< max(a1,b1); i++)
                if(ic[i][a2] .flag!= 0)
                    flag=0;
        }
        if(flag == 0)
            return false;
        else
            return true;

}
bool PlayScene::One(int a1, int a2, int b1, int b2)
{
    if(Zero( a1, a2, b1, a2) && Zero( b1, b2, b1, a2)&&ic[b1][a2].flag==0)
            return true;
        if(Zero( a1, a2, a1, b2) && Zero( b1, b2, a1, b2)&&ic[a1][b2].flag==0)
            return true;
        return false;
}
bool PlayScene::Two(int a1, int a2, int b1, int b2)
{
    for(int i = 0;i <= 12; i++)
        {
            if(i == a1 || i == b1)
                continue;
            else if(One(i, a2, b1, b2)&&Zero(i,a2,a1,a2)&&ic[i][a2].flag==0)
                return true;
        }
        for(int i = 0; i <= 10; i++)
        {
            if(i == a2 || i == b2)
                continue;
            else if(One(a1, i, b1, b2)&&Zero(a1,i,a1,a2)&&ic[a1][i].flag==0)
                return true;
        }
        return false;
}
bool PlayScene::Judge(int a1, int a2, int b1, int b2)
{
    if(Zero(a1, a2, b1, b2)|| One(a1, a2, b1, b2)|| Two( a1, a2, b1, b2))
            return true;
        else
            return false;
}
bool PlayScene::reshuffle()
{
    for(int i = 1; i <= patternum; i++)
       {
            int num = 0;
            int temX[10] = {0}, temY[10] = {0}, t = 0,t2=0;
           for(int n = 0; n <= 12; n++)
            {
                for(int m = 0; m <= 10; m++)
                    if(ic[n][m].type == i)
                    {
                        temX[t] = n;
                        temY[t++] = m;
                        num++;
                        if(num == limit)
                            break;
                    }
                if(num == limit)
                    break;
             }

           for(;temX[t2]!=0;t2++);
           if(t2%2==1)
           {
               emit reshuffletrue();
               return true;
           }

            for(int i = 0; i < limit; i++)
                for(int j = i+1; j < limit; j++)
                    if(Judge(temX[i], temY[i], temX[j], temY[j])&&ic[temX[i]][temY[i]].flag==1&&ic[temX[j]][temY[j]].flag==1)
                    {
                        hintx1 = temX[i];
                        hinty1 = temY[i];
                        hintx2 = temX[j];
                        hinty2= temY[j];
                        return false;
                    }

        }
    emit reshuffletrue();
        return true;
}

int PlayScene::min(int a, int b)
{
    if(a <= b)
        return a;
    else
        return b;
}
int PlayScene::max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

void PlayScene::process()
{
    if(Judge(x1,y1,x2,y2)&&ic[x1][y1].type==ic[x2][y2].type)
    {
        ic[x1][y1].hide();
        ic[x2][y2].hide();

        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/xiaochu.wav"));
        clickplayer->play();
        QTimer::singleShot(600,this,[=](){
           delete clickplayer;
        });

        ic[x1][y1].flag=0;
        ic[x2][y2].flag=0;
        x1=0;x2=0;y1=0;y2=0;

        tb->num+=1;
        tb->plus();
    }
}

bool PlayScene::clear()
{
    for(int i=0;i<12;i++)
        for(int j=0;j<10;j++)
            if(ic[i][j].flag==1)return false;
    return true;
}







