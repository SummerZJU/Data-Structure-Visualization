#include "dsview.h"

State state;

DSView::DSView()
{
    startCommand = std::make_shared<StartCommand>(this);
    viewStart.setStartCommand(startCommand);
    returnCommand = std::make_shared<ReturnCommand>(this);
    viewDraw.setReturnCommand(returnCommand);

    state = start;
    viewStart.flashShow(1000);
}

DSView::~DSView()
{
}

StartMenu * DSView::getStartMenu()
{
    return &viewStart;
}

DrawWindow * DSView::getDrawWindow()
{
    return &viewDraw;
}
