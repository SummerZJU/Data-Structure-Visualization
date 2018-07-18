#ifndef STARTMENU_H
#define STARTMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QFont>
#include <QImage>
#include <QPropertyAnimation>
#include "../Common/CommandBase.h"
#include "../Model/Common.h"

extern State state;

class StartMenu  : public QWidget
{
    Q_OBJECT
public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();
     void setStartCommand(std::shared_ptr<CommandBase> ptrCommand);
     void flashShow(int duration);
     void flashClose(int duration);

private:
    std::shared_ptr<CommandBase> startCommand;

    QPushButton * exitButton;
    QPushButton * treeButton;
    QPushButton * avlTreeButton;

    void initStartMenu();
    void setButton(QPushButton * button);

private slots:
    void exitSystem();
    void initTreeWindow();
    void initAVLTreeWindow();
};




#endif // STARTMENU_H
