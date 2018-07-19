#ifndef APP_H_
#define APP_H_

#include "../View/dsview.h"
#include "../ViewModel/ViewModel.h"
#include "../Model/BST.h"
#include "../Model/AVLTree.h"
#include "../Model/SplayTree.h"
#include <memory>

class APP {
    shared_ptr<DSView> dsv;
    shared_ptr<ViewModel> vm;

    // models
    shared_ptr<BST<int>> bst;
    shared_ptr<AVLTree<int>> avlTree;
    shared_ptr<SplayTree<int>> splayTree;
public:
    APP();
    virtual ~APP();
    void run();
};

#endif
