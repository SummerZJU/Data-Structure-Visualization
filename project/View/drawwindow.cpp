#include "drawwindow.h"
#include "dsview.h"

DrawWindow::DrawWindow() : DSWidget()
{
    view = nullptr;
    initDrawWindow();
}

DrawWindow::~DrawWindow()
{
}

void DrawWindow::initDrawWindow()
{
    addButton = new QPushButton("Add");
    DSWidget::setButton(addButton);
    deleteButton = new QPushButton("Delete");
    DSWidget::setButton(deleteButton);
    findButton = new QPushButton("Find");
    DSWidget::setButton(findButton);
    clearButton = new QPushButton("Clear");
    DSWidget::setButton(clearButton);
    returnButton = new QPushButton("Return");
    DSWidget::setButton(returnButton);

    addText = new QLineEdit();
    findText = new QLineEdit();
    deleteText = new QLineEdit();
    draw = new DrawWidget();

    QHBoxLayout * buttonLay1 = new QHBoxLayout();
    buttonLay1->addWidget(addButton);
    buttonLay1->addWidget(addText);
    buttonLay1->addWidget(deleteButton);
    buttonLay1->addWidget(deleteText);
    buttonLay1->addWidget(findButton);
    buttonLay1->addWidget(findText);
    QHBoxLayout * buttonLay2 = new QHBoxLayout();
    buttonLay2->addWidget(clearButton);
    buttonLay2->addStretch(1);
    buttonLay2->addWidget(returnButton);
    QHBoxLayout * buttonLay3 = new QHBoxLayout();
    buttonLay3->addWidget(draw);

    QVBoxLayout * imageLay = new QVBoxLayout();
    imageLay->addLayout(buttonLay1);
    imageLay->addLayout(buttonLay3);
    imageLay->addLayout(buttonLay2);

    QLabel * backImage;
    QPalette backPal;
    backImage = new QLabel();
    backPal.setBrush(QPalette::Background, QBrush(QPixmap(":/images/background.png")));
    backImage->setAutoFillBackground(true);
    backImage->setPalette(backPal);
    backImage->setLayout(imageLay);

    QVBoxLayout * allLay = new QVBoxLayout();
    allLay->addWidget(backImage);

    this->setLayout(allLay);
    this->resize(1200, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(returnButton, SIGNAL(clicked(bool)), this, SLOT(returnStartMenu()));
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(insertNode()));
    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteNode()));
    connect(findButton, SIGNAL(clicked(bool)), this, SLOT(findNode()));
    connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(clearWindow()));
}

void DrawWindow::returnStartMenu()
{
    state = start;
    flashClose(10);
    //returnCommand->Exec();
    (view->getStartMenu())->flashShow(100);
}

/*
void DrawWindow::setReturnCommand(std::shared_ptr<CommandBase> ptrCommand)
{
    returnCommand = ptrCommand;
}
*/

//bind trees
void DrawWindow::bind_avl_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_avl_Tree(bt);
}

void DrawWindow::setView(DSView * newView)
{
    view = newView;
}

void DrawWindow::bind_bst_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_bst_Tree(bt);
}

void DrawWindow::bind_splay_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_splay_Tree(bt);
}

void DrawWindow::bind_leftist_Heap(shared_ptr<BaseTree<int> > bt)
{
    draw->bind_leftist_Tree(bt);
}

void DrawWindow::bind_hf_Tree(shared_ptr<BaseTree<int> > bt)
{
    draw->bind_hf_Tree(bt);
}

void DrawWindow::bind_rb_Tree(shared_ptr<BaseTree<int> > bt)
{
    draw->bind_rb_Tree(bt);
}

//bind commands
//bst
void DrawWindow::bind_bst_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_bst_insert(cb);
}

void DrawWindow::bind_bst_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_bst_delete(cb);
}

void DrawWindow::bind_bst_find(shared_ptr<CommandBase> cb)
{
    draw->bind_bst_find(cb);
}

void DrawWindow::bind_bst_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_bst_clear(cb);
}

//avl
void DrawWindow::bind_avl_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_avl_insert(cb);
}

void DrawWindow::bind_avl_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_avl_delete(cb);
}

void DrawWindow::bind_avl_find(shared_ptr<CommandBase> cb)
{
    draw->bind_avl_find(cb);
}

void DrawWindow::bind_avl_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_avl_clear(cb);
}

//splay tree
void DrawWindow::bind_splay_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_splay_insert(cb);
}

void DrawWindow::bind_splay_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_splay_delete(cb);
}

void DrawWindow::bind_splay_find(shared_ptr<CommandBase> cb)
{
    draw->bind_splay_find(cb);
}

void DrawWindow::bind_splay_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_splay_clear(cb);
}

//leftist heap
void DrawWindow::bind_leftist_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_leftist_insert(cb);
}

void DrawWindow::bind_leftist_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_leftist_delete(cb);
}

void DrawWindow::bind_leftist_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_leftist_clear(cb);
}

//hf tree
void DrawWindow::bind_hf_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_hf_insert(cb);
}

void DrawWindow::bind_hf_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_hf_delete(cb);
}

void DrawWindow::bind_hf_find(shared_ptr<CommandBase> cb)
{
    draw->bind_hf_find(cb);
}

void DrawWindow::bind_hf_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_hf_clear(cb);
}


//rb Tree
void DrawWindow::bind_rb_insert(shared_ptr<CommandBase> cb)
{
    draw->bind_rb_insert(cb);
}

void DrawWindow::bind_rb_delete(shared_ptr<CommandBase> cb)
{
    draw->bind_rb_delete(cb);
}

void DrawWindow::bind_rb_find(shared_ptr<CommandBase> cb)
{
    draw->bind_rb_find(cb);
}

void DrawWindow::bind_rb_clear(shared_ptr<CommandBase> cb)
{
    draw->bind_rb_clear(cb);
}


void DrawWindow::insertNode()
{
    if(addText->text().isEmpty()) return;

    QString num = addText->text();
    int key = num.toInt();
    if(state == avlTree)
    {
        draw->avl_insert->SetParameter(make_shared<IntParameter>(key));
        draw->avl_insert->Exec();
    }
    else if(state == tree)
    {
        draw->bst_insert->SetParameter(make_shared<IntParameter>(key));
        draw->bst_insert->Exec();
    }
    else if(state == splayTree)
    {
        draw->splay_insert->SetParameter(make_shared<IntParameter>(key));
        draw->splay_insert->Exec();
    }
    else if(state == hfTree)
    {
        draw->hf_insert->SetParameter(make_shared<IntParameter>(key));
        draw->hf_insert->Exec();
    }
    else if(state == lHeap)
    {
        draw->leftist_insert->SetParameter(make_shared<IntParameter>(key));
        draw->leftist_insert->Exec();
    }
    else if(state == rbTree)
    {
        draw->rb_insert->SetParameter(make_shared<IntParameter>(key));
        draw->rb_insert->Exec();
    }
    addText->clear();
}

void DrawWindow::deleteNode()
{
    if(deleteText->text().isEmpty() && state != lHeap) return;

    QString num = deleteText->text();
    int key = num.toInt();
    if(state == avlTree)
    {
        draw->avl_delete->SetParameter(make_shared<IntParameter>(key));
        draw->avl_delete->Exec();
    }
    else if(state == tree)
    {
        draw->bst_delete->SetParameter(make_shared<IntParameter>(key));
        draw->bst_delete->Exec();
    }
    else if(state == splayTree)
    {
        draw->splay_delete->SetParameter(make_shared<IntParameter>(key));
        draw->splay_delete->Exec();
    }
    else if(state == hfTree)
    {
        draw->hf_delete->SetParameter(make_shared<IntParameter>(key));
       draw->hf_delete->Exec();
    }
    else if(state == lHeap)
    {
        draw->leftist_delete->SetParameter(make_shared<IntParameter>(key));
        draw->leftist_delete->Exec();
    }
    else if(state == rbTree)
    {
        draw->rb_delete->SetParameter(make_shared<IntParameter>(key));
        draw->rb_delete->Exec();
    }
    deleteText->clear();
}

void DrawWindow::findNode()
{
    if(findText->text().isEmpty()) return;

    QString num = findText->text();
    int key = num.toInt();
    if(state == avlTree)
    {
        draw->avl_find->SetParameter(make_shared<IntParameter>(key));
        draw->avl_find->Exec();
    }
    else if(state == tree)
    {
        draw->bst_find->SetParameter(make_shared<IntParameter>(key));
        draw->bst_find->Exec();
    }
    else if(state == splayTree)
    {
        draw->splay_find->SetParameter(make_shared<IntParameter>(key));
        draw->splay_find->Exec();
    }
    else if(state == rbTree)
    {
        draw->rb_find->SetParameter(make_shared<IntParameter>(key));
        draw->rb_find->Exec();
    }
    findText->clear();
}

void DrawWindow::clearWindow()
{
    if(state == avlTree)
    {
        draw->avl_clear->SetParameter(make_shared<IntParameter>(0));
        draw->avl_clear->Exec();
    }
    else if(state == tree)
    {
        draw->bst_clear->SetParameter(make_shared<IntParameter>(0));
        draw->bst_clear->Exec();
    }
    else if(state == splayTree)
    {
        draw->splay_clear->SetParameter(make_shared<IntParameter>(0));
        draw->splay_clear->Exec();
    }
    else if(state == hfTree)
    {
        draw->hf_clear->SetParameter(make_shared<IntParameter>(0));
        draw->hf_clear->Exec();
    }
    else if(state == lHeap)
    {
        draw->leftist_clear->SetParameter(make_shared<IntParameter>(0));
        draw->leftist_clear->Exec();
    }
    else if(state == rbTree)
    {
        draw->rb_clear->SetParameter(make_shared<IntParameter>(0));
        draw->rb_clear->Exec();
    }
}

void DrawWindow::DrawUpdate()
{
    draw->update();
}
