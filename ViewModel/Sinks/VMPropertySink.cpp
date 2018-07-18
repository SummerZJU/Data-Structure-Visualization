#include "VMPropertySink.h"
#include "../ViewModel.h"

VMPropertySink::VMPropertySink(ViewModel *pVM):
	spVM(pVM)
{

}

void VMPropertySink::OnPropertyChanged(const std::string& str)
{
	// receive notification from model

	// do ... something

	// emit to view
	spVM->Fire_OnPropertyChanged(str);
}
