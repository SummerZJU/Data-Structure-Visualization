#ifndef RBTINSERT_H_
#define RBTINSERT_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class RBTInsert : public CommandBase {
    V *spVM;

public:
    RBTInsert(V *pVM);
	virtual ~RBTInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
RBTInsert<T, V, S>::RBTInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
RBTInsert<T, V, S>::~RBTInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void RBTInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	bool res = 

        spVM->DSVRBTInsert(para);

	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}


#endif
