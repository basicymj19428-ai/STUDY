#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtWidgets/QDial>

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
    QDial *dial[3];


private slots:
    void changedData();
};
#endif // WIDGET_H
