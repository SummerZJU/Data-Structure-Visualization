#ifndef _TREE_PROPERTY_NOTIFICATION_H_
#define _TREE_PROPERTY_NOTIFICATION_H_

#include "./Common/etlbase.h"
#include <memory>

class DSView;

class TreePropertyNotification : public IPropertyNotification
{
public:
    TreePropertyNotification(DSView *pDSV);
    void OnPropertyChanged(const std::string &str);
private:
    std::shared_ptr<DSView> spDSV;
};
#endif
