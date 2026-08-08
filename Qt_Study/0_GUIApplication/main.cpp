#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();  //인스턴스의 GUI를 보이기 위해 show()함수를 호출
    return QCoreApplication::exec();
}
