#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QLabel and QLCDNumber Widget");  //프로그램 창 제목 설정

    QLabel *lbl[3];
    lbl[0] = new QLabel("I love Qt programming", this);
    lbl[0] -> setGeometry(10, 30, 130, 40);

    QPixmap pix = QPixmap(":://resources/browser.png");  //이미지 파일을 QPixmap 객체로 불러옴
    lbl[1] = new QLabel(this);
    lbl[1] -> setPixmap(pix);
    lbl[1] -> setGeometry(10, 70, 100, 100);

    QLCDNumber *lcd[3];
    lcd[0] = new QLCDNumber(2, this);  //표시 가능한 지릿수 2자리로 설정
    lcd[0] -> display(24);  //LCD에 25표시
    lcd[0] -> setGeometry(150, 30, 200, 100);
    lcd[0] -> setSegmentStyle(QLCDNumber::Outline);  //표시 스타일(Outline)

    lcd[1] = new QLCDNumber(5, this);  //표시 가능한 지릿수 5자리로 설정
    lcd[1] -> display("10:34");  //LCD 에ㅓ 10:34표시
    lcd[1] -> setGeometry(150, 140, 200, 100);
    lcd[1] -> setSegmentStyle(QLCDNumber::Filled);  //표시 스타일(Filled)

    lcd[2] = new QLCDNumber(5, this);  //표시 가능한 지릿수 5자리로 설정
    lcd[2] -> display("10:34");
    lcd[2] -> setGeometry(150, 250, 200, 100);
    lcd[2] -> setSegmentStyle(QLCDNumber::Flat);  //표시 스타일(Flat)
}

Widget::~Widget()
{
    delete ui;
}
