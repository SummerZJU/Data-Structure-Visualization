#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "../../Common/CommandBase.h"
#include <QPropertyAnimation>

class DSView;

class StartCommand : public CommandBase
{
private:
    DSView * view;

public:
    StartCommand(DSView * newView);
    ~StartCommand();
    virtual void SetParameter(std::shared_ptr<IntParameter> param);
    virtual void Exec();
};

#endif // STARTCOMMAND_H
