#ifndef OVERSCENE_H
#define OVERSCENE_H

#include <QMainWindow>

class OverScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit OverScene(QWidget *parent = nullptr,int flag=0);
    void paintEvent(QPaintEvent *event);
    int flag;
signals:
    void restart();
    void choose();

};

#endif // OVERSCENE_H
