#ifndef DRAW_H
#define DRAW_H

#include "../CommonModel/AVLTree.h"
#include "../CommonModel/BST.h"
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QVector>
#include <QString>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:

    AVLTree<int> *avl;
    BST<int> *bst;
    DrawWidget(QWidget *parent = 0);
    ~DrawWidget();
    void paintEvent(QPaintEvent *);
};
#endif // DRAW_H
