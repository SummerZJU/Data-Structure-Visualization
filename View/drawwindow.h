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
#include "Commands/returncommand.h"
#include "../Model/Common.h"
#include "draw.h"
#include "dswidget.h"

extern State state;

class DrawWindow : public DSWidget
{
    Q_OBJECT
public:
    explicit DrawWindow();
    ~DrawWindow();
    void setReturnCommand(std::shared_ptr<CommandBase> ptrCommand);

    void bind_avl_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_bst_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_splay_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_leftist_Heap(shared_ptr<BaseTree<int>> bt);
    void bind_hf_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_rb_Tree(shared_ptr<BaseTree<int>> bt);

    void bind_bst_insert(shared_ptr<CommandBase> cb);
    void bind_bst_delete(shared_ptr<CommandBase> cb);
    void bind_bst_find(shared_ptr<CommandBase> cb);
    void bind_bst_clear(shared_ptr<CommandBase> cb);

    void bind_avl_insert(shared_ptr<CommandBase> cb);
    void bind_avl_delete(shared_ptr<CommandBase> cb);
    void bind_avl_find(shared_ptr<CommandBase> cb);
    void bind_avl_clear(shared_ptr<CommandBase> cb);

    void bind_splay_insert(shared_ptr<CommandBase> cb);
    void bind_splay_delete(shared_ptr<CommandBase> cb);
    void bind_splay_find(shared_ptr<CommandBase> cb);
    void bind_splay_clear(shared_ptr<CommandBase> cb);


    void bind_leftist_insert(shared_ptr<CommandBase> cb);
    void bind_leftist_delete(shared_ptr<CommandBase> cb);
    void bind_leftist_clear(shared_ptr<CommandBase> cb);

    void bind_hf_insert(shared_ptr<CommandBase> cb);
    void bind_hf_delete(shared_ptr<CommandBase> cb);
    void bind_hf_find(shared_ptr<CommandBase> cb);
    void bind_hf_clear(shared_ptr<CommandBase> cb);

    void bind_rb_insert(shared_ptr<CommandBase> cb);
    void bind_rb_delete(shared_ptr<CommandBase> cb);
    void bind_rb_find(shared_ptr<CommandBase> cb);
    void bind_rb_clear(shared_ptr<CommandBase> cb);

    void DrawUpdate();
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

    void initDrawWindow();

private slots:
    void returnStartMenu();
    void insertNode();
    void deleteNode();
    void findNode();
    void clearWindow();
};

#endif // DRAWWINDOW_H
