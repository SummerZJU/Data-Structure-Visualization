#include "draw.h"


DrawWidget::DrawWidget(QWidget *parent):QWidget(parent)
{
    basetree_avl = shared_ptr<BaseTree<int>>();
    basetree_bst = shared_ptr<BaseTree<int>>();
    basetree_splay = shared_ptr<BaseTree<int>>();
    basetree_leftist = shared_ptr<BaseTree<int>>();
    basetree_hf = shared_ptr<BaseTree<int>>();
    basetree_rb = shared_ptr<BaseTree<int>>();

    avl_insert = shared_ptr<CommandBase>();
    avl_delete = shared_ptr<CommandBase>();
    avl_find = shared_ptr<CommandBase>();
    avl_clear = shared_ptr<CommandBase>();

    bst_insert = shared_ptr<CommandBase>();
    bst_delete = shared_ptr<CommandBase>();
    bst_find = shared_ptr<CommandBase>();
    bst_clear = shared_ptr<CommandBase>();

    splay_insert = shared_ptr<CommandBase>();
    splay_delete = shared_ptr<CommandBase>();
    splay_find = shared_ptr<CommandBase>();
    splay_clear = shared_ptr<CommandBase>();

    leftist_insert = shared_ptr<CommandBase>();
    leftist_delete = shared_ptr<CommandBase>();
    leftist_clear = shared_ptr<CommandBase>();

    hf_insert = shared_ptr<CommandBase>();
    hf_delete = shared_ptr<CommandBase>();
    hf_find = shared_ptr<CommandBase>();
    hf_clear = shared_ptr<CommandBase>();

    rb_insert = shared_ptr<CommandBase>();
    rb_delete = shared_ptr<CommandBase>();
    rb_find = shared_ptr<CommandBase>();
    rb_clear = shared_ptr<CommandBase>();
}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::bind_avl_Tree(shared_ptr<BaseTree<int>> bt)
{
    basetree_avl = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_bst_Tree(shared_ptr<BaseTree<int>> bt)
{
    basetree_bst = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_splay_Tree(shared_ptr<BaseTree<int>> bt)
{
    basetree_splay = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_leftist_Tree(shared_ptr<BaseTree<int>> bt)
{
    basetree_leftist = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_hf_Tree(shared_ptr<BaseTree<int>> bt)
{
    basetree_hf = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_rb_Tree(shared_ptr<BaseTree<int> > bt)
{
    basetree_rb = shared_ptr<BaseTree<int>>(bt);
}

void DrawWidget::bind_bst_insert(shared_ptr<CommandBase> cb)
{
    bst_insert = cb;
}

void DrawWidget::bind_bst_delete(shared_ptr<CommandBase> cb)
{
    bst_delete = cb;
}

void DrawWidget::bind_bst_find(shared_ptr<CommandBase> cb)
{
    bst_find = cb;
}

void DrawWidget::bind_bst_clear(shared_ptr<CommandBase> cb)
{
    bst_clear = cb;
}

void DrawWidget::bind_avl_insert(shared_ptr<CommandBase> cb)
{
    avl_insert = cb;
}

void DrawWidget::bind_avl_delete(shared_ptr<CommandBase> cb)
{
    avl_delete = cb;
}

void DrawWidget::bind_avl_find(shared_ptr<CommandBase> cb)
{
    avl_find = cb;
}

void DrawWidget::bind_avl_clear(shared_ptr<CommandBase> cb)
{
    avl_clear = cb;
}

void DrawWidget::bind_splay_insert(shared_ptr<CommandBase> cb)
{
    splay_insert = cb;
}

void DrawWidget::bind_splay_delete(shared_ptr<CommandBase> cb)
{
    splay_delete = cb;
}

void DrawWidget::bind_splay_find(shared_ptr<CommandBase> cb)
{
    splay_find = cb;
}

void DrawWidget::bind_splay_clear(shared_ptr<CommandBase> cb)
{
    splay_clear = cb;
}

void DrawWidget::bind_leftist_insert(shared_ptr<CommandBase> cb)
{
    leftist_insert = cb;
}

void DrawWidget::bind_leftist_delete(shared_ptr<CommandBase> cb)
{
    leftist_delete = cb;
}

void DrawWidget::bind_leftist_clear(shared_ptr<CommandBase> cb)
{
    leftist_clear = cb;
}

void DrawWidget::bind_hf_insert(shared_ptr<CommandBase> cb)
{
    hf_insert = cb;
}

void DrawWidget::bind_hf_delete(shared_ptr<CommandBase> cb)
{
    hf_delete = cb;
}

void DrawWidget::bind_hf_find(shared_ptr<CommandBase> cb)
{
    hf_find = cb;
}

void DrawWidget::bind_hf_clear(shared_ptr<CommandBase> cb)
{
    hf_clear = cb;
}

void DrawWidget::bind_rb_insert(shared_ptr<CommandBase> cb)
{
    rb_insert = cb;
}

void DrawWidget::bind_rb_delete(shared_ptr<CommandBase> cb)
{
    rb_delete = cb;
}

void DrawWidget::bind_rb_find(shared_ptr<CommandBase> cb)
{
    rb_find = cb;
}

void DrawWidget::bind_rb_clear(shared_ptr<CommandBase> cb)
{
    rb_clear = cb;
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    shared_ptr<BaseTree<int>> treeType;
    if(state == avlTree)
    {
        treeType = basetree_avl;
        paintTree(treeType);
    }
    else if(state == tree)
    {
        treeType = basetree_bst;
        paintTree(treeType);
    }
    else if(state == splayTree)
    {
        treeType = basetree_splay;
        paintTree(treeType);
    }
    else if(state == lHeap)
    {
        treeType = basetree_leftist;
        paintTree(treeType);
    }
    else if(state == hfTree)
    {
        treeType = basetree_hf;
        paintTree(treeType);
    }
    else if(state == rbTree)
    {
        paintRBT();
    }

}


void DrawWidget::paintTree(shared_ptr<BaseTree<int> > treeType)
{
    QPainter painter(this);
    if(treeType->getRoot())
    {
        QVector<BaseNode<int>*> vec;
        BaseNode<int>* t = treeType->getRoot();
        vec.push_back(t);

        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing, true);

        while(!vec.empty())
        {
            t = vec.front();
            vec.pop_front();
            if(t)
            {
                if(t->left)
                {
                    vec.push_back(t->left);
                    if(t->state == PATH && (t->left->state == PATH || t->left->state == RES))
                    {
                        pen.setColor(Qt::red);
                        painter.setPen(pen);
                    }
                    double length = sqrt(pow((30*t->left->inorderIndex - 30*t->inorderIndex),2) + pow((100*t->left->depth - 100*t->depth),2));
                    double sin_theta = (30*t->inorderIndex - 30*t->left->inorderIndex) / length;
                    double cos_theta = (100*t->left->depth - 100*t->depth) / length;
                    QPointF A(30*t->inorderIndex+40 - 30*sin_theta, 40+100*t->depth + 30*cos_theta);
                    QPointF B(30*t->left->inorderIndex+40 + 30*sin_theta, 40+100*t->left->depth - 30*cos_theta);
                    painter.drawLine(A, B);
                    //painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->left->inorderIndex+40, 40+100*t->left->depth);
                    pen.setColor(Qt::white);
                    painter.setPen(pen);
                }
                if(t->right)
                {
                    vec.push_back(t->right);
                    if(t->state == PATH && (t->right->state == PATH || t->right->state == RES))
                    {
                        pen.setColor(Qt::red);
                        painter.setPen(pen);
                    }
                    double length = sqrt(pow((30*t->right->inorderIndex - 30*t->inorderIndex),2) + pow((100*t->right->depth - 100*t->depth),2));
                    double sin_theta = (30*t->right->inorderIndex - 30*t->inorderIndex) / length;
                    double cos_theta = (100*t->right->depth - 100*t->depth) / length;
                    QPointF A(30*t->inorderIndex+40 + 30*sin_theta, 40+100*t->depth + 30*cos_theta);
                    QPointF B(30*t->right->inorderIndex+40 - 30*sin_theta, 40+100*t->right->depth - 30*cos_theta);
                    painter.drawLine(A, B);
                    //painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->right->inorderIndex+40, 40+100*t->right->depth);
                    pen.setColor(Qt::white);
                    painter.setPen(pen);
                }
            }
        }

        t = treeType->getRoot();
        vec.push_back(t);
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(20);
        font.setBold(true);
        painter.setFont(font);
        while(!vec.empty())
        {
            t = vec.front();
            vec.pop_front();
            if(t)
            {
                if(t->state == RES)
                {
                    painter.setBrush(Qt::red);
                    pen.setColor(Qt::red);
                }
                else
                {
                    painter.setBrush(Qt::NoBrush);
                    //painter.setBrush(Qt::white);
                    pen.setColor(Qt::white);
                }
                painter.setPen(pen);
                painter.drawEllipse(30*t->inorderIndex+10, 100*t->depth+10, 60, 60);
                pen.setColor(Qt::white);
                painter.setPen(pen);
                if(t->key < 10 && t->key >= 0)
                    painter.drawText(30*t->inorderIndex+32, 100*t->depth+50, QString::number(t->key));
                else if(t->key < 100)
                    painter.drawText(30*t->inorderIndex+23, 100*t->depth+50, QString::number(t->key));
                else
                    painter.drawText(30*t->inorderIndex+14, 100*t->depth+50, QString::number(t->key));
                if(t->left) vec.push_back(t->left);
                if(t->right) vec.push_back(t->right);
            }
        }
    }
}


void DrawWidget::paintRBT()
{
    QPainter painter(this);
    if(basetree_rb->getRoot() != basetree_rb->getNIL())
    {
        QVector<BaseNode<int>*> vec;
        BaseNode<int>* t = basetree_rb->getRoot();
        vec.push_back(t);

        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing, true);

        while(!vec.empty())
        {
            t = vec.front();
            vec.pop_front();
            if(t)
            {
                if(t->left != basetree_rb->getNIL())
                {
                    vec.push_back(t->left);
                    if(t->state == PATH && (t->left->state == PATH || t->left->state == RES))
                    {
                        pen.setColor(Qt::yellow);
                        painter.setPen(pen);
                    }
                    double length = sqrt(pow((30*t->left->inorderIndex - 30*t->inorderIndex),2) + pow((100*t->left->depth - 100*t->depth),2));
                    double sin_theta = (30*t->inorderIndex - 30*t->left->inorderIndex) / length;
                    double cos_theta = (100*t->left->depth - 100*t->depth) / length;
                    QPointF A(30*t->inorderIndex+40 - 30*sin_theta, 40+100*t->depth + 30*cos_theta);
                    QPointF B(30*t->left->inorderIndex+40 + 30*sin_theta, 40+100*t->left->depth - 30*cos_theta);
                    painter.drawLine(A, B);
                    //painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->left->inorderIndex+40, 40+100*t->left->depth);
                    pen.setColor(Qt::white);
                    painter.setPen(pen);
                }
                if(t->right != basetree_rb->getNIL())
                {
                    vec.push_back(t->right);
                    if(t->state == PATH && (t->right->state == PATH || t->right->state == RES))
                    {
                        pen.setColor(Qt::yellow);
                        painter.setPen(pen);
                    }
                    double length = sqrt(pow((30*t->right->inorderIndex - 30*t->inorderIndex),2) + pow((100*t->right->depth - 100*t->depth),2));
                    double sin_theta = (30*t->right->inorderIndex - 30*t->inorderIndex) / length;
                    double cos_theta = (100*t->right->depth - 100*t->depth) / length;
                    QPointF A(30*t->inorderIndex+40 + 30*sin_theta, 40+100*t->depth + 30*cos_theta);
                    QPointF B(30*t->right->inorderIndex+40 - 30*sin_theta, 40+100*t->right->depth - 30*cos_theta);
                    painter.drawLine(A, B);
                    //painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->right->inorderIndex+40, 40+100*t->right->depth);
                    pen.setColor(Qt::white);
                    painter.setPen(pen);
                }
            }
        }

        t = basetree_rb->getRoot();
        vec.push_back(t);
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(20);
        font.setBold(true);
        painter.setFont(font);
        while(!vec.empty())
        {
            t = vec.front();
            vec.pop_front();
            if(t != basetree_rb->getNIL())
            {
                if(t->state == RES)
                {
                    painter.setBrush(Qt::yellow);
                    pen.setColor(Qt::yellow);
                }
                else if(t->color == RED)
                {
                    painter.setBrush(Qt::NoBrush);
                    //painter.setBrush(Qt::white);
                    pen.setColor(Qt::red);
                }
                else
                {
                    painter.setBrush(Qt::NoBrush);
                    pen.setColor(Qt::black);
                }
                painter.setPen(pen);
                painter.drawEllipse(30*t->inorderIndex+10, 100*t->depth+10, 60, 60);
                pen.setColor(Qt::white);
                painter.setPen(pen);
                if(t->key < 10 && t->key >= 0)
                    painter.drawText(30*t->inorderIndex+32, 100*t->depth+50, QString::number(t->key));
                else if(t->key < 100)
                    painter.drawText(30*t->inorderIndex+23, 100*t->depth+50, QString::number(t->key));
                else
                    painter.drawText(30*t->inorderIndex+14, 100*t->depth+50, QString::number(t->key));
                if(t->left != basetree_rb->getNIL()) vec.push_back(t->left);
                if(t->right != basetree_rb->getNIL()) vec.push_back(t->right);
            }
        }
    }
}
