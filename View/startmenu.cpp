#include "startmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QWidget(parent)
{
    initStartMenu();
}

StartMenu::~StartMenu()
{
}

void StartMenu::initStartMenu()
{
    exitButton = new QPushButton("Exit");
    setButton(exitButton);
    treeButton = new QPushButton("Binary Search Tree");
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

    this->setLayout(allLay);
    this->resize(1200, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(exitSystem()));
    connect(treeButton, SIGNAL(clicked(bool)), this, SLOT(initTreeWindow()));
    connect(avlTreeButton, SIGNAL(clicked(bool)), this, SLOT(initAVLTreeWindow()));
}

void StartMenu::flashShow(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    this->show();
}

void StartMenu::flashClose(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

void StartMenu::setStartCommand(std::shared_ptr<CommandBase> ptrCommand)
{
    startCommand = ptrCommand;
}

void StartMenu::setButton(QPushButton * button)
{
    QPalette buttonPal;
    buttonPal.setColor(QPalette::ButtonText,Qt::white);
    QFont buttonFont("Agency FB", 20);

    button->setFlat(true);
    button->setPalette(buttonPal);
    button->setFont(buttonFont);

    button->setStyleSheet("QPushButton{color: white;}" "QPushButton:hover{color: rbg(75, 0, 130);}");
}

void StartMenu::exitSystem()
{
    flashClose(1000);
}

void StartMenu::initTreeWindow()
{
    state = tree;
    startCommand->Exec();
}

void StartMenu::initAVLTreeWindow()
{
    state = avlTree;
    startCommand->Exec();
}
