#include "drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent) : QWidget(parent)
{
     initDrawWindow();
}

DrawWindow::~DrawWindow()
{
}

void DrawWindow::initDrawWindow()
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
    draw = new DrawWidget();

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

void DrawWindow::flashShow(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    this->show();
}

void DrawWindow::flashClose(int duration)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

void DrawWindow::bind_avl_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_avl_Tree(bt);
}

void DrawWindow::bind_bst_Tree(shared_ptr<BaseTree<int>> bt)
{
    draw->bind_bst_Tree(bt);
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

void DrawWindow::setButton(QPushButton * button)
{
    QPalette buttonPal;
    buttonPal.setColor(QPalette::ButtonText,Qt::white);
    QFont buttonFont("Agency FB", 20);

    button->setFlat(true);
    button->setPalette(buttonPal);
    button->setFont(buttonFont);

    button->setStyleSheet("QPushButton{color: white;}" "QPushButton:hover{color: rbg(75, 0, 130);}");
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
    draw->update();
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
    draw->update();
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
    draw->update();
}
