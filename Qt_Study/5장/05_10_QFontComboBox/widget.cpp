#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFontComboBox *fontcombo[5];
    for(int i = 0; i < 5; i++) {
        fontcombo[i] = new QFontComboBox(this);
    }

    fontcombo[0] -> setFontFilters(QFontComboBox::AllFonts);  //모든 종류의 폰트를 표시
    fontcombo[1] -> setFontFilters(QFontComboBox::ScalableFonts);  //크기 조절이 가능한 폰트만 표시
    fontcombo[2] -> setFontFilters(QFontComboBox::NonScalableFonts);  //크기 조절이 자유롭지 않은 폰트만 표시
    fontcombo[3] -> setFontFilters(QFontComboBox::MonospacedFonts);  //일정한 문자 넓이 형태를 제공하는 폰트 표시
    fontcombo[4] -> setFontFilters(QFontComboBox::ProportionalFonts);  //가변폭 폰트만 표시

    int ypos = 30;
    for(int i = 0; i < 5; i++) {
        fontcombo[i] -> setGeometry(10, ypos, 200, 30);
        ypos += 40;
    }

    //QLabel 생성
    lbl = new QLabel("I love Qt programming", this);
    lbl -> setGeometry(10, ypos, 200, 30);

    connect(fontcombo[0], SIGNAL(currentIndexChanged(int)), this, SLOT(changedIndex(int)));
    connect(fontcombo[0], SIGNAL(currentFontChanged(QFont)), this, SLOT(changedFont(QFont)));
}

void Widget::changedIndex(int idx)
{
    qDebug("Font index : %d", idx);
}

void Widget::changedFont(QFont f)
{
    lbl -> setFont(f);
}

Widget::~Widget()
{
    delete ui;
}
