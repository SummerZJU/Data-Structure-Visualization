#ifndef SPLAYTREEINSERT_H_
#define SPLAYTREEINSERT_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

// typeanme V is ViewModel
// type parameter not only container/collection

template <typename T, typename V, typename S = less<T>>
class SplayTreeInsert : public CommandBase {
    V *spVM;

public:
    SplayTreeInsert(V *pVM);
	virtual ~SplayTreeInsert();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
SplayTreeInsert<T, V, S>::SplayTreeInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
SplayTreeInsert<T, V, S>::~SplayTreeInsert()
{
	// trival
}

template <typename T, typename V, typename S>
void SplayTreeInsert<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	bool res = 

                spVM->DSVSplayTreeInsert(para);

	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}


#endif
