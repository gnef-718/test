#include "mainscene.h"
#include "ui_mainscene.h"
#include"mypushbutton.h"
#include<QTimer>
#include"choosescene.h"
#include"helpscene.h"
#include<QPainter>
#include <QtMultimedia/QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include<QSound>


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    this->setFixedSize(1200,1000);
    this->setWindowIcon(QIcon(":/image/06.jpg"));
    this->setWindowTitle("Start");
    this->setAttribute(Qt::WA_DeleteOnClose);

    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile("E:/Qt/LinkGame/image/start.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QMediaPlayer *bgmplayer = new QMediaPlayer;
    bgmplayer->setPlaylist(playlist);
    bgmplayer->play();


    myPushButton* startbtn=new myPushButton(":/image/icons8-game-controller-100.png");
    myPushButton* helpbtn=new myPushButton(":/image/icons8-help-100.png");

    startbtn->setParent(this);
    helpbtn->setParent(this);

    startbtn->move(400-startbtn->width(),this->height()*0.6);
    helpbtn->move(800-helpbtn->width(),this->height()*0.6);

    ChooseScene* cs=new ChooseScene(this);
    HelpScene* hs=new HelpScene(this);

    connect(cs,&ChooseScene::back,[=](){
        cs->hide();
        this->show();
    });

    connect(hs,&HelpScene::back,[=](){
        hs->hide();
        this->show();
    });


    connect(startbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();

        startbtn->jumpdown();
        startbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            this->hide();
            cs->show();
        });
    });

    connect(helpbtn,&myPushButton::clicked,[=](){
        QMediaPlayer *clickplayer = new QMediaPlayer;
        clickplayer->setMedia(QUrl("E:/Qt/LinkGame/image/click.wav"));
        clickplayer->play();

        helpbtn->jumpdown();
        helpbtn->jumpup();
        QTimer::singleShot(400,this,[=](){
            this->hide();
            hs->show();
        });
    });

    connect(cs,&ChooseScene::musics,[=](){
       bgmplayer->pause();
    });
    connect(cs,&ChooseScene::musicp,[=](){
        bgmplayer->play();
    });

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/nbg.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
