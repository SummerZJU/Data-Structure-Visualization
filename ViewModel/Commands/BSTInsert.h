#ifndef BSTINSERT_H_
#define BSTINSERT_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include "../../Model/BST.h"
#include <functional>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class BSTInsert : public CommandBase {
    shared_ptr<V> spVM;

public:
    BSTInsert(V *pVM);
	virtual ~BSTInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
BSTInsert<T, V, S>::BSTInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
BSTInsert<T, V, S>::~BSTInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void BSTInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
    auto work = dynamic_pointer_cast<BST<T, S>>(spVM->getBST());
	work->insert(para);

	return;
}

#endif // BSTINSERT_H_
