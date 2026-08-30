#include <QtWidgets/QApplication>
#include "widget.h"
#include "QDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return QCoreApplication::exec();
}
