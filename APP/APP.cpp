#include "APP.h"

APP::APP():
    dsv(new DSView),
    vm(new ViewModel)
{
    // exposed attribute bind
    dsv->getDrawWindow()->bind_bst_Tree(vm->getBST());

    // exposed command bind
    dsv->getDrawWindow()->bind_bst_insert(
                shared_ptr<CommandBase>(vm->getCommandBSTInsert())
                );
    dsv->getDrawWindow()->bind_bst_delete(
                shared_ptr<CommandBase>(vm->getCommandBSTErase())
                );
    dsv->getDrawWindow()->bind_bst_find(
                shared_ptr<CommandBase>(vm->getCommandBSTFind())
                );
}

APP::~APP()
{

}

void APP::run()
{

}
