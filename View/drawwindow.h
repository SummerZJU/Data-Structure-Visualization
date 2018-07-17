#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QFont>
#include <QImage>
#include <QString>
#include <QPropertyAnimation>
#include "returncommand.h"
#include "../Model/Common.h"
#include "draw.h"

extern State state;

class DrawWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();
    void setReturnCommand(std::shared_ptr<CommandBase> ptrCommand);
    void flashShow(int duration);
    void flashClose(int duration);
    void bind_avl_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_bst_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_bst_insert(shared_ptr<CommandBase> cb);
    void bind_bst_delete(shared_ptr<CommandBase> cb);
    void bind_bst_find(shared_ptr<CommandBase> cb);
    void bind_avl_insert(shared_ptr<CommandBase> cb);
    void bind_avl_delete(shared_ptr<CommandBase> cb);
    void bind_avl_find(shared_ptr<CommandBase> cb);
private:
    std::shared_ptr<CommandBase> returnCommand;

    QPushButton * addButton;
    QPushButton * deleteButton;
    QPushButton * findButton;
    QPushButton * clearButton;
    QPushButton * returnButton;

    QLineEdit * addText;
    QLineEdit * findText;
    QLineEdit * deleteText;

    DrawWidget * draw;

    void setButton(QPushButton * button);
    void initDrawWindow();

private slots:
    void returnStartMenu();
    void insertNode();
    void deleteNode();
    void findNode();

};

#endif // DRAWWINDOW_H
