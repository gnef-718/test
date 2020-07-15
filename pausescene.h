#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include <QMainWindow>

class PauseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PauseScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
 void goon();
};

#endif // PAUSESCENE_H
