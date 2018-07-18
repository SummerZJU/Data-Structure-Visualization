#ifndef COMMANDBASE_H_
#define COMMANDBASE_H_

#include <memory>
#include "etlbase.h"             // Base class Notification 
#include "Parameter/IntParameter.h" // Base class Parameter

class CommandBase
{
public:
    CommandBase();
    virtual void Exec() = 0;
    // use count++ ?????????????????????????????  //
    virtual void SetParameter(std::shared_ptr<IntParameter> param) {parameter = param;}
protected:
    std::shared_ptr<IntParameter> parameter;
};

#endif
