#include "widget.h"
#include "QDebug"
//#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    // , ui(new Ui::Widget)
{
    // ui->setupUi(this);
    setFixedSize(QSize(300, 100));

    cmmBtn = new QCommandLinkButton("Vision", "Vision Project", this);
    cmmBtn -> setFlat(true);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));
}

void Widget::clickFunc()
{
    qDebug("QCommandLinkButton clicked.");
}

Widget::~Widget()
{
    // delete ui;
}
