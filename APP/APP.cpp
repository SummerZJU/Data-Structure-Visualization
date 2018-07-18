#include "APP.h"

APP::APP():
    dsv(new DSView),
    vm(new ViewModel),
    bst(new BST<int>),
    avlTree(new AVLTree<int>)
{
    // viewmodel bind model & notification and sinks
    vm->bindModelBST(this->bst);
    vm->bindModelAVLTree(this->avlTree);

    // viewmodel bind view-sinks by shared_ptr<IC>/<IP>
    vm->AddPropertyNotification(dsv->getTreePropertyNotification());
    vm->AddCommandNotification(dsv->getTreeCommandNotification());

    // view bind exposed (modified or not) attribute
    dsv->getDrawWindow()->bind_bst_Tree(vm->getBST());
    dsv->getDrawWindow()->bind_avl_Tree(vm->getAVLTree());

    // view bind exposed command
    dsv->getDrawWindow()->bind_bst_insert(vm->getCommandBSTInsert());
    dsv->getDrawWindow()->bind_bst_delete(vm->getCommandBSTErase());
    dsv->getDrawWindow()->bind_bst_find(vm->getCommandBSTFind());
    //dsv->getDrawWindow()->bind_bst_clear(vm->getCommandBSTClear());
    dsv->getDrawWindow()->bind_avl_insert(vm->getCommandAVLTreeInsert());
    dsv->getDrawWindow()->bind_avl_delete(vm->getCommandAVLTreeErase());
    dsv->getDrawWindow()->bind_avl_find(vm->getCommandAVLTreeFind());
    //dsv->getDrawWindow()->bind_bst_clear(vm->getCommandBSTClear());
}

APP::~APP()
{

}

void APP::run()
{

}
