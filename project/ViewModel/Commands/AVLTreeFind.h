#ifndef AVLTREEFIND_H_
#define AVLTREEFIND_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class AVLTreeFind : public CommandBase {
    V *spVM;

public:
    AVLTreeFind(V *pVM);
	virtual ~AVLTreeFind();

	virtual void Exec() override;
};

template <typename T, typename V, typename S>
AVLTreeFind<T, V, S>::AVLTreeFind(V *pVM):
	CommandBase(),
	spVM(pVM)
{

}

template <typename T, typename V, typename S>
AVLTreeFind<T, V, S>::~AVLTreeFind()
{

}

template <typename T, typename V, typename S>
void AVLTreeFind<T, V, S>::Exec()
{
	int para = *(this->parameter); // from CommandBase
	bool res = spVM->DSVAVLTreeFind(para);
	spVM->Fire_OnCommandComplete("Find Command Complete", res);

	return;
}


#endif
