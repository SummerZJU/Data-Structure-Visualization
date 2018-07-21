#ifndef LEFTISTHEAPFIND_H_
#define LEFTISTHEAPFIND_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class LeftistHeapFind : public CommandBase {
    V *spVM;

public:
    LeftistHeapFind(V *pVM);
	virtual ~LeftistHeapFind();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
LeftistHeapFind<T, V, S>::LeftistHeapFind(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
LeftistHeapFind<T, V, S>::~LeftistHeapFind()
{
	// trival
}

template <typename T, typename V, typename S>
void LeftistHeapFind<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

    // here is primitive pointer !!!
    // isn't smart pointer       !!!

    bool res = true;
	try {
		spVM->execCommandLeftistHeapFind(para);
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Find Command Complete", res);

	return;
}



#endif