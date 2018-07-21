#include "TreePropertyNotification.h"
#include "../dsview.h"
TreePropertyNotification::TreePropertyNotification(DSView *pDSV):
    spDSV(pDSV)
{

}


void TreePropertyNotification::OnPropertyChanged(const std::string &str)
{
    spDSV->getDrawWindow()->DrawUpdate();
}
