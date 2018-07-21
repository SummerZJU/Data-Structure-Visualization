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
#include "../Common/Common.h"
#include "dswidget.h"

extern State state;

class DSView;

class StartMenu  : public DSWidget
{
    Q_OBJECT
public:
    explicit StartMenu();
    ~StartMenu();
    void setView(DSView * newView);
     //void setStartCommand(std::shared_ptr<CommandBase> ptrCommand);

private:
    //std::shared_ptr<CommandBase> startCommand;

    DSView * view;

    QPushButton * exitButton;
    QPushButton * treeButton;
    QPushButton * avlTreeButton;
    QPushButton * SplayTreeButton;
    QPushButton * HFTreeButton;
    QPushButton * LHeapButton;
    QPushButton * RBTreeButton;

    void initStartMenu();

private slots:
    void exitSystem();
    void initTreeWindow();
    void initAVLTreeWindow();
    void initSplayTreeWindow();
    void initHFTreeWindow();
    void initLHeapWindow();
    void initRBTreeWindow();
};




#endif // STARTMENU_H
