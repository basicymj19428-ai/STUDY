#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

#include <QPushButton>
#include <QFocusFrame>  //특정 위젯에 포커스가 갔을때 포커스 프레임을 표시하는 클래스

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QPushButton");  //프로그램 창 제목을 QPushButton으로 설정

    QPushButton *btn[3];

    int ypos = 30;
    for(int i = 0; i < 3; i++) {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);  //%1위치에 i값을 넣음
        btn[i] -> setGeometry(10, ypos, 300, 40);
        ypos += 50;
    }

    connect(btn[0], &QPushButton::clicked, this, &Widget::btn_click);  //btn[0] 클락완료 되었을때 함수 호출
    connect(btn[0], &QPushButton::pressed, this, &Widget::btn_pressed);  //btn[0] 마우스로 누르는 순간 함수 호출
    connect(btn[0], &QPushButton::released, this, &Widget::btn_released);  //btn[0] 마우스를 놓는 순간 함수 호출

    QFocusFrame *btn_frame = new QFocusFrame(this);  //btn[0]을 QFocusFrame의 대상 위젯으로 지정
    btn_frame -> setWidget(btn[0]);
    btn_frame -> setAutoFillBackground(true);  //배경을 자동으로 채우도록 설정
}

void Widget::btn_click() {
    qDebug("Button Click");
}

void Widget::btn_pressed() {
    qDebug("Button pressed");
}

void Widget::btn_released() {
    qDebug("Button released");
}

Widget::~Widget()
{
    delete ui;
}
