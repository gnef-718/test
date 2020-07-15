#ifndef HELPSCENE_H
#define HELPSCENE_H

#include <QMainWindow>

class HelpScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit HelpScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
    void back();

};

#endif // HELPSCENE_H
