#ifndef BSTFIND_H_
#define BSTFIND_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include "../../Model/BST.h"
#include <functional>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class BSTFind : public CommandBase {
    shared_ptr<V> spVM;

public:
    BSTFind(V *pVM);
	virtual ~BSTFind();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
BSTFind<T, V, S>::BSTFind(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
BSTFind<T, V, S>::~BSTFind()
{
	// trival
}

template <typename T, typename V, typename S>
void BSTFind<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

    // here is primitive pointer !!!
    // isn't smart pointer       !!!
    auto work = dynamic_pointer_cast<BST<T, S>>(spVM->getBST());
	work->find(para);

	return;
}


#endif
