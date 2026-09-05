#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDateTimeEdit *qde1;  //객체를 가리키는 포인터 선언
    qde1 = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    qde1 -> setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");  //yyyy : 4자리 연도, MM : 2자리 월, dd : 2자리 일, hh : 시, mm : 분, ss : 초, zzz : 밀리초
    qde1 -> setGeometry(10, 30, 250, 30);

    QDateTimeEdit *qde[3];

    //연도
    qde[0] = new QDateTimeEdit(QDate::currentDate(), this);  //현재 날짜 초기값
    qde[0] -> setMinimumDate(QDate::currentDate().addYears(-3));  //3년전까지 허용
    qde[0] -> setMaximumDate(QDate::currentDate().addYears(3));  //3년 후까지 허용
    qde[0] -> setDisplayFormat("yyyy");  //연도만 화면에 표시
    qde[0] -> setGeometry(10, 90, 100, 30);

    //월
    qde[1] = new QDateTimeEdit(QDate::currentDate(), this);  //현재 날짜 초기값
    qde[1] -> setMinimumDate(QDate::currentDate().addMonths(-2));  //2개월 전까지 허용
    qde[1] -> setMaximumDate(QDate::currentDate().addMonths(2));  //2개월 후까지 허용
    qde[1] -> setDisplayFormat("MM");  //월만 화면에 표시
    qde[1] -> setGeometry(120, 90, 100, 30);

    //일
    qde[2] = new QDateTimeEdit(QDate::currentDate(), this);  //현재 날짜 초기값
    qde[2] -> setMinimumDate(QDate::currentDate().addDays(-20));  //20일 후까지 허용
    qde[2] -> setMaximumDate(QDate::currentDate().addDays(20));  //20일 전까지 허용
    qde[2] -> setDisplayFormat("dd");  //일만 화면에 표시
    qde[2] -> setGeometry(230, 90, 100, 30);
}

Widget::~Widget()
{
    delete ui;
}
