#include "startcommand.h"
#include "dsview.h"

StartCommand::StartCommand(DSView * newView)
{
    view = newView;
}

StartCommand::~StartCommand()
{
}

void StartCommand::SetParameter(std::shared_ptr<IntParameter> param)
{
}

void StartCommand::Exec()
{
    (view->getStartMenu())->flashClose(100);
    (view->getDrawWindow())->flashShow(10);
}
