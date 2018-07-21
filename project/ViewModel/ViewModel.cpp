#include "ViewModel.h"
#include "Sinks/VMPropertySink.h"
#include "../Model/BST.h"
#include "../Model/AVLTree.h"
#include "../Model/SplayTree.h"
#include "../Model/LeftistHeap.h"
#include "../Model/HFTree.h"
#include "../Model/RBT.h"
#include "Commands/BSTInsert.h"
#include "Commands/BSTErase.h"
#include "Commands/BSTFind.h"
#include "Commands/BSTClear.h"
#include "Commands/AVLTreeInsert.h"
#include "Commands/AVLTreeErase.h"
#include "Commands/AVLTreeFind.h"
#include "Commands/AVLTreeClear.h"
#include "Commands/SplayTreeInsert.h"
#include "Commands/SplayTreeErase.h"
#include "Commands/SplayTreeFind.h"
#include "Commands/SplayTreeClear.h"
#include "Commands/HFTreeClear.h"
#include "Commands/HFTreeErase.h"
#include "Commands/HFTreeFind.h"
#include "Commands/HFTreeInsert.h"
#include "Commands/LeftistHeapClear.h"
#include "Commands/LeftistHeapErase.h"
#include "Commands/LeftistHeapInsert.h"
#include "Commands/RBTClear.h"
#include "Commands/RBTErase.h"
#include "Commands/RBTFind.h"
#include "Commands/RBTInsert.h"

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

    splayTreeInsert = shared_ptr<CommandBase>(new SplayTreeInsert<int, ViewModel>(this));
    splayTreeErase = shared_ptr<CommandBase>(new SplayTreeErase<int, ViewModel>(this));
    splayTreeFind = shared_ptr<CommandBase>(new SplayTreeFind<int, ViewModel>(this));
    splayTreeClear = shared_ptr<CommandBase>(new SplayTreeClear<int, ViewModel>(this));

    leftistHeapInsert = shared_ptr<CommandBase>(new LeftistHeapInsert<int, ViewModel>(this));
    leftistHeapErase = shared_ptr<CommandBase>(new LeftistHeapErase<int, ViewModel>(this));
    leftistHeapClear = shared_ptr<CommandBase>(new LeftistHeapClear<int, ViewModel>(this));

    hfTreeInsert = shared_ptr<CommandBase>(new HFTreeInsert<int, ViewModel>(this));
    hfTreeErase = shared_ptr<CommandBase>(new HFTreeErase<int, ViewModel>(this));
    hfTreeFind = shared_ptr<CommandBase>(new HFTreeFind<int, ViewModel>(this));
    hfTreeClear = shared_ptr<CommandBase>(new HFTreeClear<int, ViewModel>(this));

    rbtInsert = shared_ptr<CommandBase>(new RBTInsert<int, ViewModel>(this));
    rbtErase = shared_ptr<CommandBase>(new RBTErase<int, ViewModel>(this));
    rbtFind = shared_ptr<CommandBase>(new RBTFind<int, ViewModel>(this));
    rbtClear = shared_ptr<CommandBase>(new RBTClear<int, ViewModel>(this));

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

void ViewModel::bindModelSplayTree(shared_ptr<BaseTree<int>> splayTree)
{
    this->splayTree = splayTree;
    splayTree->AddPropertyNotification(psink);
}


void ViewModel::bindModelLeftistHeap(shared_ptr<BaseTree<int> > leftistHeap)
{
    this->leftistHeap = leftistHeap;
    leftistHeap->AddPropertyNotification(psink);
}

void ViewModel::bindModelHFTree(shared_ptr<BaseTree<int> > hfTree)
{
    this->hfTree = hfTree;
    hfTree->AddPropertyNotification(psink);
}

void ViewModel::bindModelRBT(shared_ptr<BaseTree<int> > rbt)
{
    this->rbt = rbt;
    rbt->AddPropertyNotification(psink);
}

shared_ptr<BaseTree<int>> ViewModel::getBST() const
{
    return bst;
}

shared_ptr<BaseTree<int>> ViewModel::getAVLTree() const
{
    return avlTree;
}

shared_ptr<BaseTree<int>> ViewModel::getSplayTree() const
{
    return splayTree;
}

shared_ptr<BaseTree<int>> ViewModel::getLeftistHeap() const
{
    return leftistHeap;
}

shared_ptr<BaseTree<int>> ViewModel::getHFTree() const
{
    return hfTree;
}

shared_ptr<BaseTree<int>> ViewModel::getRBT() const
{
    return rbt;
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

shared_ptr<CommandBase> ViewModel::getCommandSplayTreeInsert() const
{
    return splayTreeInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandSplayTreeErase() const
{
    return splayTreeErase;
}

shared_ptr<CommandBase> ViewModel::getCommandSplayTreeFind() const
{
    return splayTreeFind;
}

shared_ptr<CommandBase> ViewModel::getCommandSplayTreeClear() const
{
    return splayTreeClear;
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

shared_ptr<CommandBase> ViewModel::getCommandLeftistHeapInsert() const
{
    return leftistHeapInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandLeftistHeapErase() const
{
    return leftistHeapErase;
}


shared_ptr<CommandBase> ViewModel::getCommandLeftistHeapClear() const
{
    return leftistHeapClear;
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

shared_ptr<CommandBase> ViewModel::getCommandHFTreeInsert() const
{
    return hfTreeInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandHFTreeErase() const
{
    return hfTreeErase;
}

shared_ptr<CommandBase> ViewModel::getCommandHFTreeFind() const
{
    return hfTreeFind;
}

shared_ptr<CommandBase> ViewModel::getCommandHFTreeClear() const
{
    return hfTreeClear;
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

shared_ptr<CommandBase> ViewModel::getCommandRBTInsert() const
{
    return rbtInsert;
}

shared_ptr<CommandBase> ViewModel::getCommandRBTErase() const
{
    return rbtErase;
}

shared_ptr<CommandBase> ViewModel::getCommandRBTFind() const
{
    return rbtFind;
}

shared_ptr<CommandBase> ViewModel::getCommandRBTClear() const
{
    return rbtClear;
}



// int correspond int
bool ViewModel::DSVBSTInsert(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    return    work->insert(key);
}

bool ViewModel::DSVBSTErase(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    return    work->erase(key);
}

bool ViewModel::DSVBSTFind(int key)
{
    auto work = static_pointer_cast<BST<int>>(bst);
    return    work->find(key);
}

bool ViewModel::DSVBSTClear()
{
    auto work = static_pointer_cast<BST<int>>(bst);
    work->clear();
    return true;
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

bool ViewModel::DSVAVLTreeInsert(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    return    work->insert(key);
}

bool ViewModel::DSVAVLTreeErase(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    return    work->erase(key);
}

bool ViewModel::DSVAVLTreeFind(int key)
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    return    work->find(key);
}

bool ViewModel::DSVAVLTreeClear()
{
    auto work = static_pointer_cast<AVLTree<int>>(avlTree);
    work->clear();
    return true;
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

bool ViewModel::DSVSplayTreeInsert(int key)
{
    auto work = static_pointer_cast<SplayTree<int>>(splayTree);
    return    work->insert(key);
}

bool ViewModel::DSVSplayTreeErase(int key)
{
    auto work = static_pointer_cast<SplayTree<int>>(splayTree);
    return    work->erase(key);
}

bool ViewModel::DSVSplayTreeFind(int key)
{
    auto work = static_pointer_cast<SplayTree<int>>(splayTree);
    return    work->find(key);
}

bool ViewModel::DSVSplayTreeClear()
{
    auto work = static_pointer_cast<SplayTree<int>>(splayTree);
    work->clear();
    return true;
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

bool ViewModel::DSVLeftistHeapInsert(int key)
{
    auto work = static_pointer_cast<LeftistHeap<int>>(leftistHeap);
    return    work->insert(key);
}

bool ViewModel::DSVLeftistHeapErase(int key)
{
    auto work = static_pointer_cast<LeftistHeap<int>>(leftistHeap);
    return    work->erase();
}

bool ViewModel::DSVLeftistHeapClear()
{
    auto work = static_pointer_cast<LeftistHeap<int>>(leftistHeap);
    work->clear();
    return true;
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

bool ViewModel::DSVHFTreeInsert(int key)
{
    auto work = static_pointer_cast<HFTree<int>>(hfTree);
    return    work->insert(key);
}

bool ViewModel::DSVHFTreeErase(int key)
{
    auto work = static_pointer_cast<HFTree<int>>(hfTree);
    return    work->erase(key);
}

bool ViewModel::DSVHFTreeFind(int key)
{
    auto work = static_pointer_cast<HFTree<int>>(hfTree);
    return    work->find(key);
}

bool ViewModel::DSVHFTreeClear()
{
    auto work = static_pointer_cast<HFTree<int>>(hfTree);
    work->clear();
    return true;
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


bool ViewModel::DSVRBTInsert(int key)
{
    auto work = static_pointer_cast<RBT<int>>(rbt);
    return    work->insert(key);
}

bool ViewModel::DSVRBTErase(int key)
{
    auto work = static_pointer_cast<RBT<int>>(rbt);
    return    work->erase(key);
}

bool ViewModel::DSVRBTFind(int key)
{
    auto work = static_pointer_cast<RBT<int>>(rbt);
    return    work->find(key);
}

bool ViewModel::DSVRBTClear()
{
    auto work = static_pointer_cast<RBT<int>>(rbt);
    work->clear();
    return true;
}
