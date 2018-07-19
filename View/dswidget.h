#ifndef DSWIDGET_H
#define DSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <QPalette>
#include <QPropertyAnimation>

class DSWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DSWidget(QWidget *parent = nullptr);
    virtual ~DSWidget();
    void flashShow(int duration);
    void flashClose(int duration);
protected:
   void setButton(QPushButton * button);

};

#endif // DSWIDGET_H
