#ifndef SPLAYTREEFIND_H_
#define SPLAYTREEFIND_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class SplayTreeFind : public CommandBase {
    V *spVM;

public:
    SplayTreeFind(V *pVM);
	virtual ~SplayTreeFind();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
SplayTreeFind<T, V, S>::SplayTreeFind(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
SplayTreeFind<T, V, S>::~SplayTreeFind()
{
	// trival
}

template <typename T, typename V, typename S>
void SplayTreeFind<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

    // here is primitive pointer !!!
    // isn't smart pointer       !!!

    bool res = 

                spVM->DSVSplayTreeFind(para);


	spVM->Fire_OnCommandComplete("Find Command Complete", res);

	return;
}


#endif
