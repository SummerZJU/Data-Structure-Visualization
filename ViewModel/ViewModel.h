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
    shared_ptr<BaseTree<int>> splayTree;
    shared_ptr<BaseTree<int>> leftistHeap;
    shared_ptr<BaseTree<int>> hfTree;
    shared_ptr<BaseTree<int>> rbt;

    shared_ptr<CommandBase> bstInsert;      // command-ctor is here
    shared_ptr<CommandBase> bstErase;       //
    shared_ptr<CommandBase> bstFind;        //
    shared_ptr<CommandBase> bstClear;
    shared_ptr<CommandBase> avlTreeInsert;
    shared_ptr<CommandBase> avlTreeErase;
    shared_ptr<CommandBase> avlTreeFind;
    shared_ptr<CommandBase> avlTreeClear;
    shared_ptr<CommandBase> splayTreeInsert;
    shared_ptr<CommandBase> splayTreeErase;
    shared_ptr<CommandBase> splayTreeFind;
    shared_ptr<CommandBase> splayTreeClear;
    shared_ptr<CommandBase> hfTreeInsert;
    shared_ptr<CommandBase> hfTreeErase;
    shared_ptr<CommandBase> hfTreeFind;
    shared_ptr<CommandBase> hfTreeClear;
    shared_ptr<CommandBase> leftistHeapInsert;
    shared_ptr<CommandBase> leftistHeapErase;
    shared_ptr<CommandBase> leftistHeapClear;
    shared_ptr<CommandBase> rbtInsert;
    shared_ptr<CommandBase> rbtErase;
    shared_ptr<CommandBase> rbtFind;
    shared_ptr<CommandBase> rbtClear;


    shared_ptr<IPropertyNotification> psink;       // property-sink-ctor is here

public:
	ViewModel();
	virtual ~ViewModel();
	
	// bind model & bind notification and sinks
	void bindModelBST(shared_ptr<BaseTree<int>> bst);
	void bindModelAVLTree(shared_ptr<BaseTree<int>> avlTree);
    void bindModelSplayTree(shared_ptr<BaseTree<int>> splayTree);
    void bindModelLeftistHeap(shared_ptr<BaseTree<int>> leftistHeap);
    void bindModelHFTree(shared_ptr<BaseTree<int>> hfTree);
    void bindModelRBT(shared_ptr<BaseTree<int>> rbt);

	shared_ptr<BaseTree<int>> getBST() const;
	shared_ptr<BaseTree<int>> getAVLTree() const;
    shared_ptr<BaseTree<int>> getSplayTree() const;
    shared_ptr<BaseTree<int>> getLeftistHeap() const;
    shared_ptr<BaseTree<int>> getHFTree() const;
    shared_ptr<BaseTree<int>> getRBT() const;

	shared_ptr<CommandBase> getCommandBSTInsert() const;
	shared_ptr<CommandBase> getCommandBSTErase() const;
	shared_ptr<CommandBase> getCommandBSTFind() const;
	shared_ptr<CommandBase> getCommandBSTClear() const;
	shared_ptr<CommandBase> getCommandAVLTreeInsert() const;
	shared_ptr<CommandBase> getCommandAVLTreeErase() const;
	shared_ptr<CommandBase> getCommandAVLTreeFind() const;
	shared_ptr<CommandBase> getCommandAVLTreeClear() const;
    shared_ptr<CommandBase> getCommandSplayTreeInsert() const;
    shared_ptr<CommandBase> getCommandSplayTreeErase() const;
    shared_ptr<CommandBase> getCommandSplayTreeFind() const;
    shared_ptr<CommandBase> getCommandSplayTreeClear() const;
    shared_ptr<CommandBase> getCommandLeftistHeapInsert() const;
    shared_ptr<CommandBase> getCommandLeftistHeapErase() const;
    shared_ptr<CommandBase> getCommandLeftistHeapClear() const;
    shared_ptr<CommandBase> getCommandHFTreeInsert() const;
    shared_ptr<CommandBase> getCommandHFTreeErase() const;
    shared_ptr<CommandBase> getCommandHFTreeFind() const;
    shared_ptr<CommandBase> getCommandHFTreeClear() const;
    shared_ptr<CommandBase> getCommandRBTInsert() const;
    shared_ptr<CommandBase> getCommandRBTErase() const;
    shared_ptr<CommandBase> getCommandRBTFind() const;
    shared_ptr<CommandBase> getCommandRBTClear() const;

	void execCommandBSTInsert(int key);
	void execCommandBSTErase(int key);
	void execCommandBSTFind(int key);
	void execCommandBSTClear();
	void execCommandAVLTreeInsert(int key);
	void execCommandAVLTreeErase(int key);
	void execCommandAVLTreeFind(int key);
	void execCommandAVLTreeClear();
    void execCommandSplayTreeInsert(int key);
    void execCommandSplayTreeErase(int key);
    void execCommandSplayTreeFind(int key);
    void execCommandSplayTreeClear();
    void execCommandLeftistHeapInsert(int key);
    void execCommandLeftistHeapErase(int key);
    void execCommandLeftistHeapClear();
    void execCommandHFTreeInsert(int key);
    void execCommandHFTreeErase(int key);
    void execCommandHFTreeFind(int key);
    void execCommandHFTreeClear();
    void execCommandRBTInsert(int key);
    void execCommandRBTErase(int key);
    void execCommandRBTFind(int key);
    void execCommandRBTClear();

};


#endif
