#ifndef APP_H_
#define APP_H_

#include "../View/dsview.h"
#include "../ViewModel/ViewModel.h"
#include <memory>

class APP {
    shared_ptr<DSView> dsv;
    shared_ptr<ViewModel> vm;
public:
    APP();
    virtual ~APP();
    void run();
};

#endif
