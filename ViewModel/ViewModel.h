#ifndef VIEWMODEL_H_
#define VIEWMODEL_H_

#include "../Common/TreeBase.h"
#include "../Common/CommandBase.h"
#include "../Model/AVLTree.h"
#include "../Model/BST.h"
#include "Commands/BSTInsert.h"
#include "Commands/BSTErase.h"
#include "Commands/BSTFind.h"


// member all command of viewmodel
// get mothod for them and attribute
// getAVLTree() getBST()
// get...Command()

// model is member of ViewModel 
// VS.
// viewmodel bind model

// pre declaration for command
// command couple viewmodel

// Model & Command is template
// viewmodel view just class/struct

class ViewModel {
	shared_ptr<BaseTree<int>> bst;          // ctor is here or using bindBST ???---|||??? 
	//shared_ptr<BaseTree> AVLTree;

    shared_ptr<CommandBase> bstInsert;      // ctor is here
    shared_ptr<CommandBase> bstErase;       //
    shared_ptr<CommandBase> bstFind;        //

public:
	ViewModel();
	virtual ~ViewModel();
	//void bindBST(BaseTree<int> *pBST);
	//void bindAVLTree(BaseTree<int> *pAVL);

	shared_ptr<BaseTree<int>> getBST() const;
	//BaseTree<int> *getAVL();

	shared_ptr<CommandBase> getCommandBSTInsert() const;
	shared_ptr<CommandBase> getCommandBSTErase() const;
	shared_ptr<CommandBase> getCommandBSTFind() const;

	//CommandBase *getCommandAVLTreeInsert() const;
	//CommandBase *getCommandAVLTreeErase() const;
	//CommandBase *getCommandAVLTreeFind() const;

};


#endif
