#include "returncommand.h"
#include "dsview.h"

ReturnCommand::ReturnCommand(DSView * newView)
{
    view = newView;
}

ReturnCommand::~ReturnCommand()
{
}

void ReturnCommand::SetParameter(std::shared_ptr<IntParameter> param)
{
}

void ReturnCommand::Exec()
{
    (view->getDrawWindow())->flashClose(100);
    (view->getStartMenu())->flashShow(10);
}
