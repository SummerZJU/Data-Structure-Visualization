#include "startmenu.h"
#include "dsview.h"

StartMenu::StartMenu() :  DSWidget()
{
    view = nullptr;
    initStartMenu();
}

StartMenu::~StartMenu()
{
}

void StartMenu::initStartMenu()
{
    exitButton = new QPushButton("Exit");
    DSWidget::setButton(exitButton);
    treeButton = new QPushButton("Binary Search Tree");
    DSWidget::setButton(treeButton);
    avlTreeButton = new QPushButton("AVL Tree");
    DSWidget::setButton(avlTreeButton);
    SplayTreeButton = new QPushButton("Splay Tree");
    DSWidget::setButton(SplayTreeButton);
    HFTreeButton = new QPushButton("Huffman Tree");
    DSWidget::setButton(HFTreeButton);
    LHeapButton = new QPushButton("Leftlist Heap");
    DSWidget::setButton(LHeapButton);
    RBTreeButton = new QPushButton("Red Black Tree");
    DSWidget::setButton(RBTreeButton);

    QFont titleFont("Agency FB", 40);
    QPalette titlePal;
    titlePal.setColor(QPalette::WindowText,Qt::white);

    QLabel * title1 = new QLabel("Data Structure");
    title1->setFont(titleFont);
    title1->setPalette(titlePal);
    title1->setAlignment(Qt::AlignCenter);
    QLabel * title2 = new QLabel("Visualization");
    title2->setFont(titleFont);
    title2->setPalette(titlePal);
    title2->setAlignment(Qt::AlignCenter);

    QHBoxLayout * titleLay1 = new QHBoxLayout();
    titleLay1->addWidget(title1);
    QHBoxLayout * titleLay2 = new QHBoxLayout();
    titleLay2->addWidget(title2);
    QHBoxLayout * buttonLay1 = new QHBoxLayout();
    buttonLay1->addWidget(treeButton);
    buttonLay1->addWidget(avlTreeButton);
    buttonLay1->addWidget(SplayTreeButton);
    QHBoxLayout * buttonLay2 = new QHBoxLayout();
    buttonLay2->addWidget(LHeapButton);
    buttonLay2->addWidget(HFTreeButton);
    buttonLay2->addWidget(RBTreeButton);
    QHBoxLayout * buttonLay3 = new QHBoxLayout();
    buttonLay3->addWidget(exitButton);

    QVBoxLayout * imageLay = new QVBoxLayout();
    imageLay->addStretch(2);
    imageLay->addLayout(titleLay1);
    imageLay->addLayout(titleLay2);
    imageLay->addStretch(4);
    imageLay->addLayout(buttonLay1);
    imageLay->addLayout(buttonLay2);
    imageLay->addLayout(buttonLay3);
    imageLay->addStretch(1);

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

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(exitSystem()));
    connect(treeButton, SIGNAL(clicked(bool)), this, SLOT(initTreeWindow()));
    connect(avlTreeButton, SIGNAL(clicked(bool)), this, SLOT(initAVLTreeWindow()));
    connect(SplayTreeButton, SIGNAL(clicked(bool)), this, SLOT(initSplayTreeWindow()));
    connect(HFTreeButton, SIGNAL(clicked(bool)), this, SLOT(initHFTreeWindow()));
    connect(LHeapButton, SIGNAL(clicked(bool)), this, SLOT(initLHeapWindow()));
    connect(RBTreeButton, SIGNAL(clicked(bool)), this, SLOT(initRBTreeWindow()));
}

void StartMenu::exitSystem()
{
    flashClose(1000);
}

void StartMenu::setView(DSView * newView)
{
    view = newView;
}

void StartMenu::initTreeWindow()
{
    state = tree;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}

void StartMenu::initAVLTreeWindow()
{
    state = avlTree;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}

void StartMenu::initSplayTreeWindow()
{
    state = splayTree;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}

void StartMenu::initHFTreeWindow()
{
    state = hfTree;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}

void StartMenu::initLHeapWindow()
{
    state = lHeap;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}

void StartMenu::initRBTreeWindow()
{
    state = rbTree;
    flashClose(10);
    (view->getDrawWindow())->flashShow(100);
}
