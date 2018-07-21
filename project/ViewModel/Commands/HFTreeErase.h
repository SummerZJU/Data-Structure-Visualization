#ifndef HFTREEERASE_H_
#define HFTREEERASE_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class HFTreeErase : public CommandBase {
    shared_ptr<V> spVM;

public:
    HFTreeErase(V *pVM);
	virtual ~HFTreeErase();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
HFTreeErase<T, V, S>::HFTreeErase(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
HFTreeErase<T, V, S>::~HFTreeErase()
{
	// trival
}

template <typename T, typename V,typename S>
void HFTreeErase<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	
	bool res = true;
	try {
        spVM->DSVHFTreeErase(para);
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Erase Command Complete", res);

	return;
}


#endif
