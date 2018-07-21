#ifndef LEFTISTHEAPINSERT_H_
#define LEFTISTHEAPINSERT_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class LeftistHeapInsert : public CommandBase {
    V *spVM;

public:
    LeftistHeapInsert(V *pVM);
	virtual ~LeftistHeapInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
LeftistHeapInsert<T, V, S>::LeftistHeapInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
LeftistHeapInsert<T, V, S>::~LeftistHeapInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void LeftistHeapInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	bool res = 
        spVM->DSVLeftistHeapInsert(para);

	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}




#endif
