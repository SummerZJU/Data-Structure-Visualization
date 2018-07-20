#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "../../Common/CommandBase.h"
#include <QPropertyAnimation>

class DSView;

class ReturnCommand : public CommandBase
{
private:
    DSView * view;

public:
    ReturnCommand(DSView * newView);
    ~ReturnCommand();
    virtual void SetParameter(std::shared_ptr<IntParameter> param);
    virtual void Exec();
};

#endif // RETURNCOMMAND_H
