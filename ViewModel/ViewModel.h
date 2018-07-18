#ifndef VIEWMODEL_H_
#define VIEWMODEL_H_

#include "../Common/TreeBase.h"
#include "../Common/CommandBase.h"
#include "../Common/etlbase.h"

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

/*
	Inherit Proxy_Property and Proxy_Command
	Emitter!
*/

class ViewModel : public Proxy_PropertyNotification<ViewModel>, public Proxy_CommandNotification<ViewModel> {
	shared_ptr<BaseTree<int>> bst;          // bind from model 
	shared_ptr<BaseTree<int>> avlTree;

    shared_ptr<CommandBase> bstInsert;      // command-ctor is here
    shared_ptr<CommandBase> bstErase;       //
    shared_ptr<CommandBase> bstFind;        //
    shared_ptr<CommandBase> bstClear;
    shared_ptr<CommandBase> avlTreeInsert;
    shared_ptr<CommandBase> avlTreeErase;
    shared_ptr<CommandBase> avlTreeFind;
    shared_ptr<CommandBase> avlTreeClear;

    shared_ptr<IPropertyNotification> psink;       // property-sink-ctor is here

public:
	ViewModel();
	virtual ~ViewModel();
	
	// bind model & bind notification and sinks
	void bindModelBST(shared_ptr<BaseTree<int>> bst);
	void bindModelAVLTree(shared_ptr<BaseTree<int>> avlTree);

	shared_ptr<BaseTree<int>> getBST() const;
	shared_ptr<BaseTree<int>> getAVLTree() const;

	shared_ptr<CommandBase> getCommandBSTInsert() const;
	shared_ptr<CommandBase> getCommandBSTErase() const;
	shared_ptr<CommandBase> getCommandBSTFind() const;
	shared_ptr<CommandBase> getCommandBSTClear() const;
	shared_ptr<CommandBase> getCommandAVLTreeInsert() const;
	shared_ptr<CommandBase> getCommandAVLTreeErase() const;
	shared_ptr<CommandBase> getCommandAVLTreeFind() const;
	shared_ptr<CommandBase> getCommandAVLTreeClear() const;

	void execCommandBSTInsert(int key);
	void execCommandBSTErase(int key);
	void execCommandBSTFind(int key);
	void execCommandBSTClear();
	void execCommandAVLTreeInsert(int key);
	void execCommandAVLTreeErase(int key);
	void execCommandAVLTreeFind(int key);
	void execCommandAVLTreeClear();

};


#endif
