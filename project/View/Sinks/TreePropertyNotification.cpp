#include "TreePropertyNotification.h"
#include "../dsview.h"
TreePropertyNotification::TreePropertyNotification(DSView *pDSV):
    pDSV(pDSV)
{

}


void TreePropertyNotification::OnPropertyChanged(const std::string &str)
{
    pDSV->getDrawWindow()->DrawUpdate();
}
