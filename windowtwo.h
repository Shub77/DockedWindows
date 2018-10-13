#ifndef WINDOWTWO_H
#define WINDOWTWO_H

#include <QMainWindow>

class WindowOne;

namespace Ui {
class WindowTwo;
class WindowOne;
}

class WindowTwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowTwo(QWidget *parent = nullptr);
    ~WindowTwo();
    void moveEvent(QMoveEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void closeEvent(QCloseEvent *event);
    WindowOne *windowOne;
    bool skipevent_two;

private:
    Ui::WindowTwo *ui;

};
#endif
