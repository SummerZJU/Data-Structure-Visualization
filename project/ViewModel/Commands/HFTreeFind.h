#ifndef HFTREEFIND_H_
#define HFTREEFIND_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;


template <typename T, typename V, typename S = less<T>>
class HFTreeFind : public CommandBase {
    shared_ptr<V> spVM;

public:
    HFTreeFind(V *pVM);
	virtual ~HFTreeFind();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
HFTreeFind<T, V, S>::HFTreeFind(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
HFTreeFind<T, V, S>::~HFTreeFind()
{
	// trival
}

template <typename T, typename V, typename S>
void HFTreeFind<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase

    // here is primitive pointer !!!
    // isn't smart pointer       !!!

    bool res = true;
	try {
		spVM->execCommandHFTreeFind(para);
	} catch(const exception& e) {
		res = false;
	}

	spVM->Fire_OnCommandComplete("Find Command Complete", res);

	return;
}



#endif