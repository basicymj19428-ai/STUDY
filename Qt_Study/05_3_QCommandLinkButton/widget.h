#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCommandLinkButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    QCommandLinkButton *cmmBtn;

private slots:
    void clickFunc();
};
#endif // WIDGET_H
