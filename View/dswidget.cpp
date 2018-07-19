#include "dswidget.h"

DSWidget::DSWidget(QWidget *parent) : QWidget(parent)
{
}

DSWidget::~DSWidget()
{
}

void DSWidget::flashShow(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    this->show();
}

void DSWidget::flashClose(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

void DSWidget::setButton(QPushButton * button)
{
    QPalette buttonPal;
    buttonPal.setColor(QPalette::ButtonText,Qt::white);
    QFont buttonFont("Agency FB", 20);

    button->setFlat(true);
    button->setPalette(buttonPal);
    button->setFont(buttonFont);

    button->setStyleSheet("QPushButton{color: white;}" "QPushButton:hover{color: rbg(75, 0, 130);}");
}
