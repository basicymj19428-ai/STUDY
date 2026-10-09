#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFontComboBox>
#include <QLabel>

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

    QLabel *lbl;

private slots:
    void changedIndex(int idx);
    void changedFont(QFont f);
};
#endif // WIDGET_H
