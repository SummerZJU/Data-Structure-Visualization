#ifndef DRAW_H
#define DRAW_H

#include "../Common/TreeBase.h"
#include "../Common/CommandBase.h"
#include "../Model/Common.h"
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QVector>
#include <QString>
#include <memory>

extern State state;

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    DrawWidget(QWidget *parent = 0);
    virtual ~DrawWidget();
    void paintEvent(QPaintEvent *);
    void paintTree(shared_ptr<BaseTree<int>> treeType);

    void bind_avl_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_bst_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_splay_Tree(shared_ptr<BaseTree<int>> bt);
    void bind_leftist_Tree(shared_ptr<BaseTree<int>> bt);
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

    std::shared_ptr<BaseTree<int>> basetree_avl;
    std::shared_ptr<BaseTree<int>> basetree_bst;
    std::shared_ptr<BaseTree<int>> basetree_splay;
    std::shared_ptr<BaseTree<int>> basetree_leftist;
    std::shared_ptr<BaseTree<int>> basetree_hf;
    std::shared_ptr<BaseTree<int>> basetree_rb;

    std::shared_ptr<CommandBase> avl_insert;
    std::shared_ptr<CommandBase> avl_delete;
    std::shared_ptr<CommandBase> avl_find;
    std::shared_ptr<CommandBase> avl_clear;

    std::shared_ptr<CommandBase> bst_insert;
    std::shared_ptr<CommandBase> bst_delete;
    std::shared_ptr<CommandBase> bst_find;
    std::shared_ptr<CommandBase> bst_clear;

    std::shared_ptr<CommandBase> splay_insert;
    std::shared_ptr<CommandBase> splay_delete;
    std::shared_ptr<CommandBase> splay_find;
    std::shared_ptr<CommandBase> splay_clear;

    std::shared_ptr<CommandBase> leftist_insert;
    std::shared_ptr<CommandBase> leftist_delete;
    std::shared_ptr<CommandBase> leftist_clear;

    std::shared_ptr<CommandBase> hf_insert;
    std::shared_ptr<CommandBase> hf_delete;
    std::shared_ptr<CommandBase> hf_find;
    std::shared_ptr<CommandBase> hf_clear;

    std::shared_ptr<CommandBase> rb_insert;
    std::shared_ptr<CommandBase> rb_delete;
    std::shared_ptr<CommandBase> rb_find;
    std::shared_ptr<CommandBase> rb_clear;
};
#endif // DRAW_H
