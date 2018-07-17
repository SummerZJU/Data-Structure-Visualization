#include <QApplication>
#include "../APP/APP.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // run ?

    APP *ap = new APP;
    return a.exec();
}
