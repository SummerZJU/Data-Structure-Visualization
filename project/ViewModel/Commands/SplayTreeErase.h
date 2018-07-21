#ifndef SPLAYTREEERASE_H_
#define SPLAYTREEERASE_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class SplayTreeErase : public CommandBase {
    V *spVM;

public:
    SplayTreeErase(V *pVM);
	virtual ~SplayTreeErase();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
SplayTreeErase<T, V, S>::SplayTreeErase(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
SplayTreeErase<T, V, S>::~SplayTreeErase()
{
	// trival
}

template <typename T, typename V,typename S>
void SplayTreeErase<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	
	bool res = true;
	try {
		spVM->execCommandSplayTreeErase(para);
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Erase Command Complete", res);

	return;
}


#endif