#ifndef DSVIEW_H
#define DSVIEW_H

#include "../Model/Common.h"
#include "startmenu.h"
#include "drawwindow.h"
#include "startcommand.h"
#include "returncommand.h"

class DSView
{
private:
    StartMenu viewStart;
    DrawWindow viewDraw;
    std::shared_ptr<StartCommand> startCommand;
    std::shared_ptr<ReturnCommand> returnCommand;

public:
    DSView();
    ~DSView();

    StartMenu * getStartMenu();
    DrawWindow * getDrawWindow();

};

#endif // DSVIEW_H
