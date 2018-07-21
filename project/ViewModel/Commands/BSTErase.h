#ifndef BSTERASE_H_
#define BSTERASE_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class BSTErase : public CommandBase {
    V *spVM;

public:
    BSTErase(V *pVM);
	virtual ~BSTErase();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
BSTErase<T, V, S>::BSTErase(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
BSTErase<T, V, S>::~BSTErase()
{
	// trival
}

template <typename T, typename V,typename S>
void BSTErase<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	
	bool res = true;
	try {
		spVM->execCommandBSTErase(para);
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Erase Command Complete", res);

	return;
}

#endif
