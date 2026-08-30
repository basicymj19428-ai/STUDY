#include "widget.h"
#include "ui_widget.h"
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimeEdit *qte[10];

    QTime ti1 = QTime(6, 24, 0, 0);  //시간, 분, 초, 밀리초

    qte[0] = new QTimeEdit(ti1, this);
    qte[0] -> setGeometry(10, 30, 150, 30);

    QTime t;
    t = ti1.addSecs(70);
    qte[1] = new QTimeEdit(t, this);
    qte[1] -> setGeometry(10, 70, 150, 30);

    qte[2] = new QTimeEdit(ti1.addSecs(2), this);
    qte[2] -> setGeometry(10, 110, 150, 30);

    QTime ti2 = QTime::currentTime();
    qte[3] = new QTimeEdit(ti2.currentTime(), this);
    qte[3] -> setGeometry(10, 150, 150, 30);

    QTime ti3 = QTime::fromString("03:32", "hh:mm");

    QLabel *lbl_fromString = new QLabel(ti3.toString(), this);
    lbl_fromString -> setGeometry(10, 190, 150, 30);

    QTime ti4 = QTime(6, 25, 34, 323);
    qDebug("Hour : %d", ti4.hour());
    qDebug("min : %d", ti4.minute());
    qDebug("sec : %d", ti4.second());
    qDebug("msec : %d", ti4.msec());

    QTime ti5 = QTime(7, 10, 23, 122);
    QLabel *lbl_toString = new QLabel(ti5.toString("AP hh:mm:ss:zzz"), this);
    lbl_toString -> setGeometry(10, 10, 150, 30);
}

Widget::~Widget()
{
    delete ui;
}
