#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    int ypos = 30;  //y축 위치
    int val[3] = {50, 100, 200};  //QSpinBox에 넣을 정수 초기값
    double double_val[3] = {50.5, 127.32, 171.342};  //QDoubleSpinBox에 넣을 실수 초깃값

    for(int i = 0; i < 3; i++) {
        spin[i] = new QSpinBox(this);
        spin[i] -> setMinimum(10);  //최소 : 10
        spin[i] -> setMaximum(300);  //최대 : 300
        spin[i] -> setValue(val[i]);
        spin[i] -> setGeometry(10, ypos, 100, 30);

        doublespin[i] = new QDoubleSpinBox(this);
        doublespin[i] -> setMinimum(10.0);  //최소 : 10.0
        doublespin[i] -> setMaximum(300.0);  //최대 : 300.0 
        doublespin[i] -> setValue(double_val[i]);
        doublespin[i] -> setGeometry(120, ypos, 100, 30);

        spin[i] -> setPrefix("$ ");  //QSpinBox 값 앞에 $ 문자열 표시
        doublespin[i] -> setSuffix(" mm");  //QDoubleSpinBox 값 뒤에 mm 문자열 표시

        ypos += 40;
    }

    //spin[0]의 값이 변경되면 valueChange() 슬롯함수 호출
    connect(spin[0], SIGNAL(valueChanged(int)), this, SLOT(valueChange()));

    //doublespin[0]의 값이 변경되면 double_valueChange() 슬롯함수 호출
    connect(doublespin[0], SIGNAL(valueChanged(double)), this, SLOT(double_valueChange()));
}

void Widget::valueChange()
{
    qDebug("change value : %d", spin[0] -> value());
}

void Widget::double_valueChange()
{
    qDebug("change double value : %3.2lf", doublespin[0] -> value());
}

Widget::~Widget()
{
    delete ui;
}
