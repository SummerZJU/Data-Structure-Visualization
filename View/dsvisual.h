#ifndef DSVISUAL_H
#define DSVISUAL_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QFont>
#include <QImage>
#include <QString>
#include "draw.h"
#include <QPropertyAnimation>

class DSVisual : public QObject
{
    Q_OBJECT

public:
    explicit DSVisual(QObject *parent = 0);
    ~DSVisual();

private:
    QWidget * startMenu;
    QWidget * treeWindow;
    QWidget * avlTreeWindow;

    QPushButton * exitButton;
    QPushButton * treeButton;
    QPushButton * avlTreeButton;
    QPushButton * addButton;
    QPushButton * deleteButton;
    QPushButton * findButton;
    QPushButton * clearButton;
    QPushButton * returnButton;

    QLineEdit * addText;
    QLineEdit * findText;
    QLineEdit * deleteText;
    
    DrawWidget * draw;
    void initStartMenu();
    void setMainLayOut(QWidget * mainWindow);
    void setButton(QPushButton * button);
    void closeWindow(QWidget * window);

private slots:
    void exitSystem();
    void initTreeWindow();
    void initAVLTreeWindow();
    void returnStartMenu();
    void insertNode();
    void deleteNode();
    void findNode();
};

#endif // DSVISUAL_H
