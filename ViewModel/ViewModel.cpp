#include "ViewModel.h"
#include "Sinks/VMPropertySink.h"
#include "../Model/BST.h"
#include "../Model/AVLTree.h"
#include "Commands/BSTInsert.h"
#include "Commands/BSTErase.h"
#include "Commands/BSTFind.h"
#include "Commands/BSTClear.h"
#include "Commands/AVLTreeInsert.h"
#include "Commands/AVLTreeErase.h"
#include "Commands/AVLTreeFind.h"
#include "Commands/AVLTreeClear.h"


ViewModel::ViewModel()
    // default ctor of shared_ptr<T>
	// wild shared_ptr !!!
{
    // exposed
    bstInsert = shared_ptr<CommandBase>(new BSTInsert<int, ViewModel>(this));
    bstErase = shared_ptr<CommandBase>(new BSTErase<int, ViewModel>(this));
    bstFind = shared_ptr<CommandBase>(new BSTFind<int, ViewModel>(this));
    bstClear = shared_ptr<CommandBase>(new BSTClear<int, ViewModel>(this));

    avlTreeInsert = shared_ptr<CommandBase>(new AVLTreeInsert<int, ViewModel>(this));
    avlTreeErase = shared_ptr<CommandBase>(new AVLTreeErase<int, ViewModel>(this));
    avlTreeFind = shared_ptr<CommandBase>(new AVLTreeFind<int, ViewModel>(this));
    avlTreeClear = shared_ptr<CommandBase>(new AVLTreeClear<int, ViewModel>(this));

    psink = shared_ptr<IPropertyNotification>(new VMPropertySink(this));
}

ViewModel::~ViewModel()
{
	//  all shared ptr
	//  happly
}

// view model bind model & notification and sinks
void ViewModel::bindModelBST(shared_ptr<BaseTree<int>> bst)
{
    this->bst = bst;
    // ??? !!! ??? Command Notifucation is useless ??? !!! ???
    bst->AddPropertyNotification(psink);
}

void ViewModel::bindModelAVLTree(shared_ptr<BaseTree<int>> avlTree)
{
    this->avlTree = avlTree;
    avlTree->AddPropertyNotification(psink);
}

shared_ptr<BaseTree<int>> ViewModel::getBST() const
{
    return bst;
}

shared_ptr<BaseTree<int>> ViewModel::getAVLTree() const
{
    return avlTree;
}

/////////////////////////////////////////////////////
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
/////////////////////////////////////////////////////

shared_ptr<CommandBase> ViewModel::getCommandBSTInsert() const
{
    return bstInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandBSTErase() const
{
    return bstErase;
}

shared_ptr<CommandBase> ViewModel::getCommandBSTFind() const
{
    return bstFind;
}

shared_ptr<CommandBase> ViewModel::getCommandBSTClear() const
{
    return bstClear;
}

/////////////////////////////////////////////////////
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
/////////////////////////////////////////////////////

shared_ptr<CommandBase> ViewModel::getCommandAVLTreeInsert() const
{
    return avlTreeInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandAVLTreeErase() const
{
    return avlTreeErase;
}

shared_ptr<CommandBase> ViewModel::getCommandAVLTreeFind() const
{
    return avlTreeFind;
}

shared_ptr<CommandBase> ViewModel::getCommandAVLTreeClear() const
{
    return avlTreeClear;
}

/////////////////////////////////////////////////////
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
/////////////////////////////////////////////////////

// int correspond int
void ViewModel::execCommandBSTInsert(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    work->insert(key);
}

void ViewModel::execCommandBSTErase(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    work->erase(key);
}

void ViewModel::execCommandBSTFind(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    work->find(key);
}

void ViewModel::execCommandBSTClear()
{
    auto work = static_pointer_cast<BST<int>>(bst);
    work->clear();
}

/////////////////////////////////////////////////////
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
//                                                 //
/////////////////////////////////////////////////////

void ViewModel::execCommandAVLTreeInsert(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    work->insert(key);
}

void ViewModel::execCommandAVLTreeErase(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    work->erase(key);
}

void ViewModel::execCommandAVLTreeFind(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    work->find(key);
}

void ViewModel::execCommandAVLTreeClear()
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    work->clear();
}
