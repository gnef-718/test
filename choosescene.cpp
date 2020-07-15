#include "choosescene.h"
#include"mypushbutton.h"
#include<QTimer>
#include"playscene.h"
#include<QPainter>
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>


ChooseScene::ChooseScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Choose Mode");
    this->setAttribute(Qt::WA_DeleteOnClose);

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

     myPushButton* levelbtn1=new myPushButton(":/image/icons8-1st-100.png",":/image/icons8-level-1-100 (1).png");
     myPushButton* levelbtn2=new myPushButton(":/image/icons8-circled-2-100.png",":/image/icons8-circled-2-c-100.png");
     myPushButton* levelbtn3=new myPushButton(":/image/icons8-circled-3-100.png",":/image/icons8-circled-3-c-100.png");
     myPushButton* levelbtn4=new myPushButton(":/image/icons8-circled-4-100.png",":/image/icons8-circled-4-c-100.png");
     myPushButton* levelbtn5=new myPushButton(":/image/icons8-circled-5-100.png",":/image/icons8-circled-5-c-100.png");
     myPushButton* levelbtn6=new myPushButton(":/image/icons8-circled-6-100.png",":/image/icons8-circled-6-c-100.png");
     myPushButton* levelbtn7=new myPushButton(":/image/icons8-circled-7-100.png",":/image/icons8-circled-7-c-100.png");
     myPushButton* levelbtn8=new myPushButton(":/image/icons8-circled-8-100.png",":/image/icons8-circled-8-c-100.png");
     myPushButton* levelbtn9=new myPushButton(":/image/icons8-circled-9-100.png",":/image/icons8-circled-9-c-100.png");

     levelbtn1->setParent(this);
     levelbtn2->setParent(this);
     levelbtn3->setParent(this);
     levelbtn4->setParent(this);
     levelbtn5->setParent(this);
     levelbtn6->setParent(this);
     levelbtn7->setParent(this);
     levelbtn8->setParent(this);
     levelbtn9->setParent(this);

     levelbtn1->move(400,350);
     levelbtn2->move(550,350);
     levelbtn3->move(700,350);
     levelbtn4->move(400,525);
     levelbtn5->move(550,525);
     levelbtn6->move(700,525);
     levelbtn7->move(400,700);
     levelbtn8->move(550,700);
     levelbtn9->move(700,700);


     connect(levelbtn1,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn1->jumpdown();
         levelbtn1->jumpup();

         PlayScene* ps=new PlayScene(this,1);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();

         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn2,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn2->jumpdown();
         levelbtn2->jumpup();
         PlayScene* ps=new PlayScene(this,2);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn3,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn3->jumpdown();
         levelbtn3->jumpup();

         PlayScene* ps=new PlayScene(this,3);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn4,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn4->jumpdown();
         levelbtn4->jumpup();

         PlayScene* ps=new PlayScene(this,4);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn5,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn5->jumpdown();
         levelbtn5->jumpup();

         PlayScene* ps=new PlayScene(this,5);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn6,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn6->jumpdown();
         levelbtn6->jumpup();

         PlayScene* ps=new PlayScene(this,6);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn7,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();


         levelbtn7->jumpdown();
         levelbtn7->jumpup();

         PlayScene* ps=new PlayScene(this,7);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn8,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();

         levelbtn8->jumpdown();
         levelbtn8->jumpup();

         PlayScene* ps=new PlayScene(this,8);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });
     connect(levelbtn9,&myPushButton::clicked,[=](){
         QMediaPlayer *clickplayer = new QMediaPlayer;
         clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
         clickplayer->play();         

         levelbtn9->jumpdown();
         levelbtn9->jumpup();

         PlayScene* ps=new PlayScene(this,9);

         QTimer::singleShot(400,this,[=](){
             this->hide();
             ps->show();
             delete clickplayer;
         });
         connect(ps,&PlayScene::home,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             emit back();
         });
         connect(ps,&PlayScene::back,[=](){
             ps->hide();
             QTimer::singleShot(400,this,[=](){
                 delete ps;
             });
             this->show();
         });
         connect(ps,&PlayScene::musicstop,[=](){
             emit musics();
         });
         connect(ps,&PlayScene::musicplay,[=](){
             emit musicp();
         });
     });







}

void ChooseScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/choose.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
