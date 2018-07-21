#ifndef HFTREECLEAR_H_
#define HFTREECLEAR_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class HFTreeClear : public CommandBase {
    V *spVM;

public:
    HFTreeClear(V *pVM);
	virtual ~HFTreeClear();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
HFTreeClear<T, V, S>::HFTreeClear(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
HFTreeClear<T, V, S>::~HFTreeClear()
{
	// trival
}

template <typename T, typename V, typename S>
void HFTreeClear<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

    // here is primitive pointer !!!
    // isn't smart pointer       !!!

    bool res = true;
	try {
		spVM->execCommandHFTreeClear();
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Clear Command Complete", res);

	return;
}


#endif