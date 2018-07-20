#include "startcommand.h"
#include "../dsview.h"

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
    (view->getStartMenu())->DSWidget::flashClose(100);
    (view->getDrawWindow())->DSWidget::flashShow(10);
}
