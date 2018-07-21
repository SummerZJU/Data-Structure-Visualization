#ifndef AVLTREECLEAR_H_
#define AVLTREECLEAR_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class AVLTreeClear : public CommandBase {
    V *spVM;

public:
    AVLTreeClear(V *pVM);
	virtual ~AVLTreeClear();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
AVLTreeClear<T, V, S>::AVLTreeClear(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
AVLTreeClear<T, V, S>::~AVLTreeClear()
{
	// trival
}

template <typename T, typename V, typename S>
void AVLTreeClear<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

   	// parameter is useless !
    // dynamic is useless !

	// smart pointer of base template/class
	bool res = true;

	spVM->execCommandAVLTreeClear(); // no exception !!!
	spVM->Fire_OnCommandComplete("Clear Command Complete", res);
	
	return;
}


#endif