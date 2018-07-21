#include "APP.h"

APP::APP():
    dsv(new DSView),
    vm(new ViewModel),
    bst(new BST<int>),
    avlTree(new AVLTree<int>),
    splayTree(new SplayTree<int>),
    leftistHeap(new LeftistHeap<int>),
    hfTree(new HFTree<int>),
    rbTree(new RBT<int>)
{
    // viewmodel bind model & notification and sinks
    vm->bindModelBST(this->bst);
    vm->bindModelAVLTree(this->avlTree);
    vm->bindModelSplayTree(this->splayTree);
    vm->bindModelLeftistHeap(this->leftistHeap);
    vm->bindModelHFTree(this->hfTree);
    vm->bindModelRBT(this->rbTree);

    // viewmodel bind view-sinks by shared_ptr<IC>/<IP>
    vm->AddPropertyNotification(dsv->getTreePropertyNotification());
    vm->AddCommandNotification(dsv->getTreeCommandNotification());

    // view bind exposed (modified or not) attribute
    dsv->getDrawWindow()->bind_bst_Tree(vm->getBST());
    dsv->getDrawWindow()->bind_avl_Tree(vm->getAVLTree());
    dsv->getDrawWindow()->bind_splay_Tree(vm->getSplayTree());
    dsv->getDrawWindow()->bind_leftist_Heap(vm->getLeftistHeap());
    dsv->getDrawWindow()->bind_hf_Tree(vm->getHFTree());
    dsv->getDrawWindow()->bind_rb_Tree(vm->getRBT());

    // view bind exposed command
    dsv->getDrawWindow()->bind_bst_insert(vm->getCommandBSTInsert());
    dsv->getDrawWindow()->bind_bst_delete(vm->getCommandBSTErase());
    dsv->getDrawWindow()->bind_bst_find(vm->getCommandBSTFind());
    dsv->getDrawWindow()->bind_bst_clear(vm->getCommandBSTClear());

    dsv->getDrawWindow()->bind_avl_insert(vm->getCommandAVLTreeInsert());
    dsv->getDrawWindow()->bind_avl_delete(vm->getCommandAVLTreeErase());
    dsv->getDrawWindow()->bind_avl_find(vm->getCommandAVLTreeFind());
    dsv->getDrawWindow()->bind_avl_clear(vm->getCommandAVLTreeClear());

    dsv->getDrawWindow()->bind_splay_insert(vm->getCommandSplayTreeInsert());
    dsv->getDrawWindow()->bind_splay_delete(vm->getCommandSplayTreeErase());
    dsv->getDrawWindow()->bind_splay_find(vm->getCommandSplayTreeFind());
    dsv->getDrawWindow()->bind_splay_clear(vm->getCommandSplayTreeClear());

    dsv->getDrawWindow()->bind_leftist_insert(vm->getCommandLeftistHeapInsert());
    dsv->getDrawWindow()->bind_leftist_delete(vm->getCommandLeftistHeapErase());
    dsv->getDrawWindow()->bind_leftist_clear(vm->getCommandLeftistHeapClear());

    dsv->getDrawWindow()->bind_hf_insert(vm->getCommandHFTreeInsert());
    dsv->getDrawWindow()->bind_hf_delete(vm->getCommandHFTreeErase());
    dsv->getDrawWindow()->bind_hf_find(vm->getCommandHFTreeFind());
    dsv->getDrawWindow()->bind_hf_clear(vm->getCommandHFTreeClear());

    dsv->getDrawWindow()->bind_rb_insert(vm->getCommandRBTInsert());
    dsv->getDrawWindow()->bind_rb_delete(vm->getCommandRBTErase());
    dsv->getDrawWindow()->bind_rb_find(vm->getCommandRBTFind());
    dsv->getDrawWindow()->bind_rb_clear(vm->getCommandRBTClear());

}

APP::~APP()
{

}

void APP::run()
{

}
