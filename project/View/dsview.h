#ifndef DSVIEW_H
#define DSVIEW_H

#include "../Common/Common.h"
#include "startmenu.h"
#include "drawwindow.h"
#include "Commands/startcommand.h"
#include "Commands/returncommand.h"
#include "Sinks/TreeCommandNotification.h"
#include "Sinks/TreePropertyNotification.h"

class DSView
{
private:
    StartMenu viewStart;
    DrawWindow viewDraw;
    std::shared_ptr<StartCommand> startCommand;
    std::shared_ptr<ReturnCommand> returnCommand;

    shared_ptr<ICommandNotification> spTCN;
    shared_ptr<IPropertyNotification> spTPN;

public:
    DSView();
    ~DSView();

    StartMenu * getStartMenu();
    DrawWindow * getDrawWindow();

    std::shared_ptr<ICommandNotification> getTreeCommandNotification();
    std::shared_ptr<IPropertyNotification> getTreePropertyNotification();
};

#endif // DSVIEW_H
