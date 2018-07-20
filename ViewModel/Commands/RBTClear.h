#ifndef RBTCLEAR_H_
#define RBTCLEAR_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class RBTClear : public CommandBase {
    shared_ptr<V> spVM;

public:
    RBTClear(V *pVM);
	virtual ~RBTClear();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
RBTClear<T, V, S>::RBTClear(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
RBTClear<T, V, S>::~RBTClear()
{
	// trival
}

template <typename T, typename V, typename S>
void RBTClear<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

   	// parameter is useless !
    // dynamic is useless !

	// smart pointer of base template/class
	bool res = true;

	spVM->execCommandRBTClear(); // no exception !!!
	spVM->Fire_OnCommandComplete("Clear Command Complete", res);
	
	return;
}


#endif