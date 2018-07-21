#include "TreeCommandNotification.h"
#include "../dsview.h"

TreeCommandNotification::TreeCommandNotification(DSView *pDSV) : spDSV(pDSV)
{
    ie = std::shared_ptr<InsertError>(new InsertError());
    de = std::shared_ptr<DeleteError>(new DeleteError());
    fe = std::shared_ptr<FindError>(new FindError());
}

void TreeCommandNotification::OnCommandComplete(const std::string &str, bool bOK)
{
    if(!bOK)
    {
        if(str == "Insert Command Complete")
        {
            ie->show();
        }
        else if(str == "Erase Command Complete")
        {
            de->show();
        }
        else if(str == "Find Command Complete")
        {
            fe->show();
        }
    }
}
