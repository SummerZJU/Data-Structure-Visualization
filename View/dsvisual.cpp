#include "dsvisual.h"
#include "ui_dsvisual.h"

DSVisual::DSVisual(QObject *parent) :
    QObject(parent)
{

   startMenu = nullptr;
   treeWindow = nullptr;
   avlTreeWindow = nullptr;

   initStartMenu();
}

DSVisual::~DSVisual()
{
}

void DSVisual::initStartMenu()
{
    exitButton = new QPushButton("Exit");
    exitButton->setFlat(true);
    treeButton = new QPushButton("Binary Tree");
    treeButton->setFlat(true);
    avlTreeButton = new QPushButton("AVL Tree");
    avlTreeButton->setFlat(true);

    QHBoxLayout * buttonLay = new QHBoxLayout();
    buttonLay->addWidget(treeButton);
    buttonLay->addWidget(avlTreeButton);
    buttonLay->addWidget(exitButton);

    QWidget * titleImage;
    QPalette pal;
    pal.setBrush(QPalette::Background, QBrush(QPixmap("D:/DSVision/title.png")));
    titleImage = new QWidget();
    titleImage->setAutoFillBackground(true);
    titleImage->setPalette(pal);
    titleImage->setMinimumHeight(130);

    QVBoxLayout * allLay = new QVBoxLayout();
    allLay->addWidget(titleImage);
    allLay->addLayout(buttonLay);

    startMenu = new QWidget();
    startMenu->setWindowTitle("Welcome to Data Structure Visualization System");
    startMenu->setLayout(allLay);
    startMenu->resize(900, 600);
    startMenu->show();

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(exitSystem()));
    connect(treeButton, SIGNAL(clicked(bool)), this, SLOT(initTreeWindow()));
    connect(avlTreeButton, SIGNAL(clicked(bool)), this, SLOT(initTreeWindow()));
}

void DSVisual::exitSystem()
{
    qApp->exit(0);
}

void DSVisual::initTreeWindow()
{
    startMenu->close();

    treeWindow = new QWidget();
    mainLayOut(treeWindow);
    treeWindow->setWindowTitle("Binary Tree Visualization");
    treeWindow->resize(900, 600);
    treeWindow->show();
}

void DSVisual::initAVLTreeWindow()
{
    startMenu->close();

    avlTreeWindow = new QWidget();
    mainLayOut(treeWindow);
    avlTreeWindow->setWindowTitle("AVL Tree Visualization");
    avlTreeWindow->resize(900, 600);
    avlTreeWindow->show();
}

void DSVisual::mainLayOut(QWidget* mainWindow)
{
    addButton = new QPushButton("Add");
    addButton->setFlat(true);
    deleteButton = new QPushButton("Delete");
    deleteButton->setFlat(true);
    findButton = new QPushButton("Find");
    findButton->setFlat(true);
    clearButton = new QPushButton("Clear");
    clearButton->setFlat(true);
    returnButton = new QPushButton("Return");
    returnButton->setFlat(true);

    addText = new QLineEdit();
    findText = new QLineEdit();
    deleteText = new QLineEdit();

    QHBoxLayout * buttonLay1 = new QHBoxLayout();
    buttonLay1->addWidget(addButton);
    buttonLay1->addWidget(addText);
    buttonLay1->addWidget(deleteButton);
    buttonLay1->addWidget(deleteText);
    buttonLay1->addWidget(findButton);
    buttonLay1->addWidget(findText);
    QHBoxLayout * buttonLay2 = new QHBoxLayout();
    buttonLay2->addWidget(returnButton);

    QVBoxLayout * allLay = new QVBoxLayout();
    allLay->addLayout(buttonLay1);
    allLay->addStretch(1);
    allLay->addLayout(buttonLay2);

    mainWindow->setLayout(allLay);

    connect(returnButton, SIGNAL(clicked(bool)), this, SLOT(returnStartMenu()));
}

void DSVisual::returnStartMenu()
{
    if(treeWindow) treeWindow->close();
    if(avlTreeWindow) avlTreeWindow->close();

    initStartMenu();
}
