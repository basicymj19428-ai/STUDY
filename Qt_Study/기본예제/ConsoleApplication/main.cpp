#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug("Hello World!");  //메시지를 출력

    return QCoreApplication::exec();  //프로그램이 종료되지 않도록 해주는 역할
}