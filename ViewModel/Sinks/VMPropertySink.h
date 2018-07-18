#ifndef VMPROPERTYSINK_H_
#define VMPROPERTYSINK_H_

#include "../../Common/etlbase.h"
#include <memory>

// pre declaration

class ViewModel;

class VMPropertySink : public IPropertyNotification {
	std::shared_ptr<ViewModel> spVM;
public:
	VMPropertySink(ViewModel *pVM);
	virtual void OnPropertyChanged(const std::string& str) override;
};

#endif