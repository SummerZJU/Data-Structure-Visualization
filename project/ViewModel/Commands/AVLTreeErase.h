#ifndef AVLTREEERASE_H_
#define AVLTREEERASE_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>
 
using namespace std;

template <typename T, typename V, typename S = less<T>>
class AVLTreeErase : public CommandBase {
    V *spVM;

public:
    AVLTreeErase(V *pVM);
	virtual ~AVLTreeErase();

	virtual void Exec() override;
};

template <typename T, typename V, typename S>
AVLTreeErase<T, V, S>::AVLTreeErase(V *pVM):
	CommandBase(),
	spVM(pVM)
{

}

template <typename T, typename V, typename S>
AVLTreeErase<T, V, S>::~AVLTreeErase()
{

}

template <typename T, typename V, typename S>
void AVLTreeErase<T, V, S>::Exec()
{
	int para = *(this->parameter); // from CommandBase
	bool res = spVM->DSVAVLTreeErase(para);
	spVM->Fire_OnCommandComplete("Erase Command Complete", res);

	return;
}


#endif
