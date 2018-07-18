#ifndef AVLTREEINSERT_H_
#define AVLTREEINSERT_H_

#include "../../Common/CommandBase.h"
#include "../../Common/TreeBase.h"
#include <functional>
#include <exception>
#include <memory>

using namespace std;

template <typename T, typename V, typename S = less<T>>
class AVLTreeInsert : public CommandBase {
    shared_ptr<V> spVM;

public:
    AVLTreeInsert(V *pVM);
	virtual ~AVLTreeInsert();

	virtual void Exec() override;
};

template <typename T, typename V, typename S>
AVLTreeInsert<T, V, S>::AVLTreeInsert(V *pVM):
	CommandBase(),
	spVM(pVM)
{

}

template <typename T, typename V, typename S>
AVLTreeInsert<T, V, S>::~AVLTreeInsert()
{

}

template <typename T, typename V, typename S>
void AVLTreeInsert<T, V, S>::Exec()
{
	int para = *(this->parameter); // from CommandBase
	bool res = true;
	try {
		spVM->execCommandAVLTreeInsert(para);
	} catch(const exception& e) {
		res = false;
	}
	spVM->Fire_OnCommandComplete("Insert Command Complete", res);

	return;
}

#endif