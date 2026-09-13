#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    int xpos = 30;  //x축 시작 위치(Dial)

    for(int i = 0; i < 3; i++, xpos +=110) {  //i++할떄 마다 x좌표 110씩 증가
        dial[i] = new QDial(this);
        dial[i] -> setRange(0, 100);  //Dial이 가질수 있는 값의 범위 설정(0 ~ 100)
        dial[i] -> setGeometry(xpos, 30, 100, 100);
    }

    dial[0] -> setNotchesVisible(true);  //주변에 눈금 표시
    connect(dial[0], &QDial::valueChanged, this, &Widget::changedData);
}

void Widget::changedData() {
    qDebug("QDial 1 value : %d", dial[0] -> value());
}

Widget::~Widget()
{
    delete ui;
}
