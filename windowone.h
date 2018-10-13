#ifndef WINDOWONE_H
#define WINDOWONE_H

#include <QMainWindow>

class WindowTwo;

namespace Ui {
class WindowOne;
class WindowTwo;
}

class WindowOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowOne(QWidget *parent = nullptr);
    ~WindowOne();
    void moveEvent(QMoveEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    WindowTwo *windowTwo;
    bool skipevent_one;

private:
    Ui::WindowOne *ui;

};
#endif
