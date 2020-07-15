#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include"mypushbutton.h"

class ChooseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
    void back();
    void musics();
    void musicp();


};

#endif // CHOOSESCENE_H
