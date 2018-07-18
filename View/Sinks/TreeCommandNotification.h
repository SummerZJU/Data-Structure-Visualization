#ifndef _TREE_COMMAND_NOTIFICATION_H_
#define _TREE_COMMAND_NOTIFICATION_H_

#include "./Common/etlbase.h"
#include "../ErrorView/DeleteError.h"
#include "../ErrorView/InsertError.h"
#include "../ErrorView/FindError.h"

class DSView;

class TreeCommandNotification : public ICommandNotification
{
public:
    TreeCommandNotification(DSView * pDSV);
    void OnCommandComplete(const std::string &str, bool bOK);
private:
    std::shared_ptr<DSView> spDSV;
    std::shared_ptr<InsertError> ie;
    std::shared_ptr<DeleteError> de;
    std::shared_ptr<FindError> fe;

};

#endif
