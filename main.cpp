#include <QApplication>
#include "windowone.h"
#include "windowtwo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowOne one;
    WindowTwo two(&one);
    one.windowTwo = &two;
    two.windowOne = &one;

    two.show();
    one.show();

    return a.exec();
}
