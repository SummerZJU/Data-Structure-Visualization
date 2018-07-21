#ifndef BSTFIND_H_
#define BSTFIND_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class BSTFind : public CommandBase {
    V *spVM;

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

    bool res = spVM->DSVBSTFind(para);


	spVM->Fire_OnCommandComplete("Find Command Complete", res);

	return;
}


#endif
