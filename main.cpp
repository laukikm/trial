#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

#include "window.h"
#include "widget.h"
#include "widget2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    Window w;
    w.show();

    QPushButton button ("Hello world !");
    button.show();
    */

    Widget w;
    w.show();

    Widget2 w2;
    w2.show();

    return a.exec();
}
