#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;


private:
    QButtonGroup *m_chk_group[2];
    QCheckBox *m_exclusive[3];
    QCheckBox *m_non_exclusive[3];

//시그널(이벤트)을 처리할 함수를 선언
private slots:
    void slot_chkChanged();
};
#endif // WIDGET_H
