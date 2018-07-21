#ifndef LEFTISTHEAPERASE_H_
#define LEFTISTHEAPERASE_H_


#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class LeftistHeapErase : public CommandBase {
    V *spVM;

public:
    LeftistHeapErase(V *pVM);
	virtual ~LeftistHeapErase();

	virtual void Exec() override;
};

// command bind model
// viewmodel bind model
// just couple model in viewmodel
template <typename T, typename V, typename S>
LeftistHeapErase<T, V, S>::LeftistHeapErase(V *pVM):
	CommandBase(),
	spVM(pVM)
{
	// ctor from primitive pointer to smart pointer	
}

template <typename T, typename V, typename S>
LeftistHeapErase<T, V, S>::~LeftistHeapErase()
{
	// trival
}

template <typename T, typename V,typename S>
void LeftistHeapErase<T, V, S>::Exec()
{
	// actual T is wonderful
	// naive here
	int para = *(this->parameter); // from CommandBase
	
	bool res =
        spVM->DSVLeftistHeapErase(para);


	spVM->Fire_OnCommandComplete("Erase Command Complete", res);

	return;
}

#endif
