#ifndef BSTINSERT_H_
#define BSTINSERT_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class BSTInsert : public CommandBase {
    V *spVM;

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
	bool res = spVM->DSVBSTInsert(para);

	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}

#endif // BSTINSERT_H_
