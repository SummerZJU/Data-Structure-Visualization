#ifndef HFTREEINSERT_H_
#define HFTREEINSERT_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class HFTreeInsert : public CommandBase {
    V *spVM;

public:
    HFTreeInsert(V *pVM);
	virtual ~HFTreeInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
HFTreeInsert<T, V, S>::HFTreeInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
HFTreeInsert<T, V, S>::~HFTreeInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void HFTreeInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	bool res = true;
	try {
		spVM->execCommandHFTreeInsert(para);
	} catch(const exception& e) {
		res = false;
	}
	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}


#endif