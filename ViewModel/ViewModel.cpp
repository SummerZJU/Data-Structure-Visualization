#include "ViewModel.h"

ViewModel::ViewModel():
	bst(),
	bstInsert(),
	bstErase(),
	bstFind()
	// wild ptr !!!
{
    // exposed
    bst = shared_ptr<BaseTree<int>>(new BST<int>);

    // exposed
    bstInsert = shared_ptr<CommandBase>(new BSTInsert<int, ViewModel>(this));
    bstErase = shared_ptr<CommandBase>(new BSTErase<int, ViewModel>(this));
    bstFind = shared_ptr<CommandBase>(new BSTFind<int, ViewModel>(this));
}

ViewModel::~ViewModel()
{
	//  all shared ptr
	//  happly
}

shared_ptr<BaseTree<int>> ViewModel::getBST() const
{
    return bst;
}

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
