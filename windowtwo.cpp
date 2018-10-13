#include "windowtwo.h"
#include "ui_windowtwo.h"
#include "windowone.h"

#include <QCloseEvent>

WindowTwo::WindowTwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowTwo)
{
    ui->setupUi(this);
    this->skipevent_two = false;
    this->installEventFilter(this);
}

void WindowTwo::moveEvent(QMoveEvent *event)
{
    if (this->skipevent_two)
    {
        return;
    }

    QRect ogeo;
    QRect geo;

    ogeo = windowOne->geometry();
    geo = this->geometry();
    geo.moveLeft(geo.left() - ogeo.width() - 10);
    geo.setHeight(ogeo.height());
    geo.setWidth(ogeo.width());
    windowOne->setGeometry(geo);


}

bool WindowTwo::eventFilter(QObject *watched, QEvent *event)
{
    bool ret = false;
    if (event->type() == QEvent::NonClientAreaMouseButtonPress) {
        if (this->isMinimized()) {
            this->windowOne->skipevent_one = false;
        }
        else {
                this->windowOne->skipevent_one = true;
        }
        ret = false;
    }
    else if (event->type() == QEvent::NonClientAreaMouseButtonRelease) {
        this->windowOne->skipevent_one = false;
        ret = false;
    }
    else if (event->type() == QEvent::WindowStateChange) {
        if (this->isMinimized()) {
            this->windowOne->skipevent_one = false;
            this->windowOne->showMinimized();
            ret = false;
        }
    }
    else {
        ret = QMainWindow::eventFilter(watched, event);
    }
    return ret;
}

void WindowTwo::closeEvent(QCloseEvent *event)
{
    windowOne->close();
    event->accept();
}

WindowTwo::~WindowTwo()
{
    delete ui;
}
