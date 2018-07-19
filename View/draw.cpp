#include "draw.h"


DrawWidget::DrawWidget(QWidget *parent):QWidget(parent)
{
    basetree_avl = shared_ptr<BaseTree<int>>();
    basetree_bst = shared_ptr<BaseTree<int>>();
    avl_insert = shared_ptr<CommandBase>();
    avl_delete = shared_ptr<CommandBase>();
    avl_find = shared_ptr<CommandBase>();
    avl_clear = shared_ptr<CommandBase>();
    bst_insert = shared_ptr<CommandBase>();
    bst_delete = shared_ptr<CommandBase>();
    bst_find = shared_ptr<CommandBase>();
    bst_clear = shared_ptr<CommandBase>();
    this->show();
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

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(state == avlTree)
    {
        if(basetree_avl->getRoot())
        {
            QVector<BaseNode<int>*> vec;
            BaseNode<int>* t = basetree_avl->getRoot();
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

            t = basetree_avl->getRoot();
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
                        //painter.setBrush(Qt::red);
                        pen.setColor(Qt::red);
                    }
                    else
                    {
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
    else if(state == tree)
    {
        if(basetree_bst->getRoot())
        {
            QVector<BaseNode<int>*> vec;
            BaseNode<int>* t = basetree_bst->getRoot();
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

            t = basetree_bst->getRoot();
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
                        //painter.setBrush(Qt::red);
                        pen.setColor(Qt::red);
                    }
                    else
                    {
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
}
