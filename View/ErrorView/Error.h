#ifndef _Error_H_
#define _Error_H_

#include <QString>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QHBoxLayout>
#include <QPushButton>

class Error : public QDialog
{
    Q_OBJECT
public:
    Error(QWidget * parent = 0);
    virtual ~Error();
    void SetString();
    void SetTitle();
    QString ErrorStr;
    QString ErrorTitle;
private:
    QLabel * ErrorLable;
};
#endif
