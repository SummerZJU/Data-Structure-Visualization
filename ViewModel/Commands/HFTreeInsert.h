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
class HFTeeInsert : public CommandBase {
    shared_ptr<V> spVM;

public:
    HFTeeInsert(V *pVM);
	virtual ~HFTeeInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
HFTeeInsert<T, V, S>::HFTeeInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
HFTeeInsert<T, V, S>::~HFTeeInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void HFTeeInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	bool res = true;
	try {
		spVM->execCommandHFTeeInsert(para);
	} catch(const exception& e) {
		res = false;
	}
	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}


#endif