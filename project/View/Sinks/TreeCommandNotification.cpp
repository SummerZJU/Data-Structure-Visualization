#include "TreeCommandNotification.h"
#include "../dsview.h"

TreeCommandNotification::TreeCommandNotification(DSView *pDSV) : pDSV(pDSV)
{
    ie = new InsertError();
    de = new DeleteError();
    fe = new FindError();
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
