#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ui->pushButton : 시그널을 발생하는 오브젝트
    //SIGNAL(clicked()) : 시그널을 발생하는 종류
    //this : 시그널과 연결할 Slot함수가 있는 인스턴스 명
    //SLOT(slot_clicked()) : 호출할 Slot 함수
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_clicked()
{
    qDebug() <<"Hello World";
}