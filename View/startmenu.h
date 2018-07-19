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
#include "dswidget.h"

extern State state;

class StartMenu  : public DSWidget
{
    Q_OBJECT
public:
    explicit StartMenu();
    ~StartMenu();
     void setStartCommand(std::shared_ptr<CommandBase> ptrCommand);

private:
    std::shared_ptr<CommandBase> startCommand;

    QPushButton * exitButton;
    QPushButton * treeButton;
    QPushButton * avlTreeButton;
    QPushButton * SplayTreeButton;
    QPushButton * HFTreeButton;
    QPushButton * LHeapButton;

    void initStartMenu();

private slots:
    void exitSystem();
    void initTreeWindow();
    void initAVLTreeWindow();
    void initSplayTreeWindow();
    void initHFTreeWindow();
    void initLHeapWindow();
};




#endif // STARTMENU_H
