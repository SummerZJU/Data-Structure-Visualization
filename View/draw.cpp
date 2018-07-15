#include "draw.h"

State state;

DrawWidget::DrawWidget(QWidget *parent):QWidget(parent)
{
    avl = new AVLTree<int>;
    bst = new BST<int>;
}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(state == avlTree)
    {
        if(avl->getRoot())
        {
            QVector<TNode<int>*> vec;
            TNode<int>* t = avl->getRoot();
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
                        painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->left->inorderIndex+40, 40+100*t->left->depth);
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
                        painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->right->inorderIndex+40, 40+100*t->right->depth);
                        pen.setColor(Qt::white);
                        painter.setPen(pen);
                    }
                }
            }

            t = avl->getRoot();
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
                        painter.setBrush(Qt::white);
                        pen.setColor(Qt::white);
                    }
                    painter.setPen(pen);
                    painter.drawEllipse(30*t->inorderIndex+10, 100*t->depth+10, 50, 50);
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawText(30*t->inorderIndex+25, 100*t->depth+50, QString::number(t->key));
                    if(t->left) vec.push_back(t->left);
                    if(t->right) vec.push_back(t->right);
                }
            }
        }
    }
    else if(state == tree)
    {
        if(bst->getRoot())
        {
            QVector<BSTNode<int>*> vec;
            BSTNode<int>* t = bst->getRoot();
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
                        painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->left->inorderIndex+40, 40+100*t->left->depth);
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
                        painter.drawLine(30*t->inorderIndex+40, 40+100*t->depth, 30*t->right->inorderIndex+40, 40+100*t->right->depth);
                        pen.setColor(Qt::white);
                        painter.setPen(pen);
                    }
                }
            }

            t = bst->getRoot();
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
                        painter.setBrush(Qt::white);
                        pen.setColor(Qt::white);
                    }
                    painter.setPen(pen);
                    painter.drawEllipse(30*t->inorderIndex+10, 100*t->depth+10, 50, 50);
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawText(30*t->inorderIndex+25, 100*t->depth+50, QString::number(t->key));
                    if(t->left) vec.push_back(t->left);
                    if(t->right) vec.push_back(t->right);
                }
            }
        }
    }
}
