#include "drawwindow.h"

DrawWindow::DrawWindow() : DSWidget()
{
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
    returnCommand->Exec();
}

void DrawWindow::setReturnCommand(std::shared_ptr<CommandBase> ptrCommand)
{
    returnCommand = ptrCommand;
}

void DrawWindow::bind_avl_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_avl_Tree(bt);
}

void DrawWindow::bind_bst_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_bst_Tree(bt);
}

void DrawWindow::bind_splay_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_splay_Tree(bt);
}

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

void DrawWindow::insertNode()
{
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
    addText->clear();
}

void DrawWindow::deleteNode()
{
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
    deleteText->clear();
}

void DrawWindow::findNode()
{
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
}

void DrawWindow::DrawUpdate()
{
    draw->update();
}
