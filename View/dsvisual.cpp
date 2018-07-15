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
    setButton(exitButton);
    treeButton = new QPushButton("Binary Tree");
    setButton(treeButton);
    avlTreeButton = new QPushButton("AVL Tree");
    setButton(avlTreeButton);

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
    QHBoxLayout * buttonLay = new QHBoxLayout();
    buttonLay->addWidget(treeButton);
    buttonLay->addWidget(avlTreeButton);
    buttonLay->addWidget(exitButton);

    QVBoxLayout * imageLay = new QVBoxLayout();
    imageLay->addStretch(2);
    imageLay->addLayout(titleLay1);
    imageLay->addLayout(titleLay2);
    imageLay->addStretch(4);
    imageLay->addLayout(buttonLay);
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

    startMenu = new QWidget();
    //startMenu->setWindowTitle("Welcome to Data Structure Visualization System");
    startMenu->setLayout(allLay);
    startMenu->resize(1200, 800);
    startMenu->setWindowFlag(Qt::FramelessWindowHint);
    startMenu->show();

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(exitSystem()));
    connect(treeButton, SIGNAL(clicked(bool)), this, SLOT(initTreeWindow()));
    connect(avlTreeButton, SIGNAL(clicked(bool)), this, SLOT(initAVLTreeWindow()));
}

void DSVisual::exitSystem()
{
    qApp->exit(0);
}

void DSVisual::initTreeWindow()
{
    startMenu->close();

    treeWindow = new QWidget();
    setMainLayOut(treeWindow);
    //treeWindow->setWindowTitle("Binary Tree Visualization");
    treeWindow->show();
}

void DSVisual::initAVLTreeWindow()
{
    startMenu->close();

    avlTreeWindow = new QWidget();
    setMainLayOut(avlTreeWindow);
    //avlTreeWindow->setWindowTitle("AVL Tree Visualization");
    avlTreeWindow->show();
}

void DSVisual::setMainLayOut(QWidget* mainWindow)
{
    addButton = new QPushButton("Add");
    setButton(addButton);
    deleteButton = new QPushButton("Delete");
    setButton(deleteButton);
    findButton = new QPushButton("Find");
    setButton(findButton);
    clearButton = new QPushButton("Clear");
    setButton(clearButton);
    returnButton = new QPushButton("Return");
    setButton(returnButton);

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
    buttonLay2->addStretch(1);
    buttonLay2->addWidget(returnButton);

    QVBoxLayout * imageLay = new QVBoxLayout();
    imageLay->addLayout(buttonLay1);
    imageLay->addStretch(1);
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

    mainWindow->setLayout(allLay);
    mainWindow->resize(1200, 800);
    mainWindow->setWindowFlag(Qt::FramelessWindowHint);

    connect(returnButton, SIGNAL(clicked(bool)), this, SLOT(returnStartMenu()));
}

void DSVisual::returnStartMenu()
{
    if(treeWindow) treeWindow->close();
    if(avlTreeWindow) avlTreeWindow->close();

    initStartMenu();
}

void DSVisual::setButton(QPushButton * button)
{
    QPalette buttonPal;
    buttonPal.setColor(QPalette::ButtonText,Qt::white);
    QFont buttonFont("Agency FB", 20);

    button->setFlat(true);
    button->setPalette(buttonPal);
    button->setFont(buttonFont);

    button->setStyleSheet("QPushButton{color: white;}"
                         "QPushButton:hover{color: rbg(75, 0, 130);}");
}
