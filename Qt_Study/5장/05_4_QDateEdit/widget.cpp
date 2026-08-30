#include "widget.h"
#include "ui_widget.h"
#include "qdebug.h"

#include <QDate>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDate dt1 = QDate(2023, 1, 1);
    QDate dt2 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1.addYears(2), this);  // dt1(2023.01.01)에 2년을 더한 날짜
    dateEdit[0] -> setGeometry(10, 10, 140, 40);

    dateEdit[1] = new QDateEdit(dt1.addMonths(3), this);  // dt1(2023.01.01)에 3개월을 더한 날짜
    dateEdit[1] -> setGeometry(160, 10, 140, 40);

    dateEdit[2] = new QDateEdit(dt1.addDays(10), this);  // dt1(2023.01.01)에 10일을 더한 날짜
    dateEdit[2] -> setGeometry(310, 10, 140, 40);

    dateEdit[3] = new QDateEdit(dt2, this);  //현재 날짜(dt2)를 표시하는 QDateEdit 생성
    dateEdit[3] -> setGeometry(10, 60, 140, 40);

    qDebug("Day of year : %d", dt1.dayOfYear());
    qDebug("End Day : %d", dt1.daysInMonth());
    qDebug("End Day : %d", dt1.daysInYear());

    QDate dt3 = QDate::fromString("2002.06.26", "yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26", "MM.dd");

    lbl[0] = new QLabel(dt3.toString(), this);
    lbl[0] -> setGeometry(10, 110, 150, 30);

    lbl[1] = new QLabel(dt4.toString(), this);
    lbl[1] -> setGeometry(10, 150, 150, 30);

    // 2011년 6월 27일이 유효한 날짜인지 검사
    if(QDate::isValid(2011, 6, 27))
    {
        qDebug("2011.06.27 true");  //출력
    }
    else
    {
        qDebug("2011.06.27 false");
    }
}

Widget::~Widget()
{
    delete ui;
}
