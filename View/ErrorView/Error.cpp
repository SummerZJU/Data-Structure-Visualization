#include "Error.h"

Error::Error(QWidget * parent) : QDialog(parent)
{
    this->setFixedHeight(80);
    this->setFixedWidth(200);
    QFont font("Microsoft YaHei", 20);
    ErrorLable = new QLabel();
    ErrorLable->setFont(font);
    ErrorLable->setAlignment(Qt::AlignCenter);
    QHBoxLayout * Lay = new QHBoxLayout();
    Lay->addWidget(ErrorLable);
    this->setLayout(Lay);
}

Error::~Error()
{
}


void Error::SetTitle()
{
    setWindowTitle(ErrorTitle);
}

void Error::SetString()
{
    ErrorLable->setText(ErrorStr);
}

