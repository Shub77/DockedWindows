#include "windowone.h"
#include "ui_windowone.h"
#include "windowtwo.h"

WindowOne::WindowOne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowOne)
{
    ui->setupUi(this);
    this->skipevent_one = false;
    this->installEventFilter(this);
}

void WindowOne::moveEvent(QMoveEvent *event)
{
    if (this->skipevent_one ) {
        return;
    }

    QRect ogeo;
    QRect geo;

    ogeo = windowTwo->geometry();
    geo = this->geometry();
    geo.moveLeft(geo.left() + geo.width() + 10);
    geo.setHeight(ogeo.height());
    geo.setWidth(ogeo.width());
    windowTwo->setGeometry(geo);

}

bool WindowOne::eventFilter(QObject *watched, QEvent *event)
{
    bool ret = false;
    if (event->type() == QEvent::NonClientAreaMouseButtonPress) {
        if (this->isMinimized()) {
            this->windowTwo->skipevent_two = false;
        }
        else {
            this->windowTwo->skipevent_two = true;
            ret = false;
        }
    }
    else if (event->type() == QEvent::NonClientAreaMouseButtonRelease) {
        this->windowTwo->skipevent_two = false;
        ret = false;
    }
    else if (event->type() == QEvent::WindowStateChange) {
        if (this->isMinimized()) {
            this->windowTwo->skipevent_two = false;
            ret = false;
        }
    }
    else {
        ret = QMainWindow::eventFilter(watched, event);
    }
    return ret;
}

WindowOne::~WindowOne()
{
    delete ui;
}
