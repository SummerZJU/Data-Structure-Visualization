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
#include <QPropertyAnimation>

typedef int State;

class DSVisual : public QObject
{
    Q_OBJECT

public:
    explicit DSVisual(QObject *parent = 0);
    ~DSVisual();

private:
    enum{start, tree, avlTree};
    State state;

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

    void initStartMenu();
    void setMainLayOut(QWidget * mainWindow);
    void setButton(QPushButton * button);
    void closeWindow(QWidget * window);

private slots:
    void exitSystem();
    void initTreeWindow();
    void initAVLTreeWindow();
    void returnStartMenu();
};

#endif // DSVISUAL_H
