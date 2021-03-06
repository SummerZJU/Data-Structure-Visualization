#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <queue>
#include <vector>
#include <algorithm>
#include "../Common/TreeBase.h"
#include "../Common/Exception/ModelException.h"
#include "../Common/Common.h"

template<typename T>
struct HFNode : public BaseNode<T>
{
    HFNode(const T& value);
    virtual ~HFNode();
};

template <typename T>
HFNode<T>::HFNode(const T& value) : BaseNode<T>(value)
{
}

template <typename T>
HFNode<T>::~HFNode()
{
}

template<typename T, typename S = less<T> >
class HFTree : public BaseTree<T, S>
{
private:
    std::vector<T> content;
    void create();

public:
    HFTree();
    virtual ~HFTree();

    bool insert(const T& value);
    bool erase(const T& value);
    void clear();
    HFNode<T> *find(const T& value);
};

template <typename T, typename S>
HFTree<T, S>::HFTree() : BaseTree<T, S>()
{
}

template <typename T, typename S>
HFTree<T, S>::~HFTree()
{
}

template <typename T, typename S>
HFNode<T> *HFTree<T, S>::find(const T& value)
{
    HFNode<T> *ret = nullptr;
        BaseNode<T> *work = this->root;
    // reset to OTHER!
        this->levelorder();
    // reset to OTHER!
    while(work) {
        work->state = PATH;
        if(work->key == value) {
            ret = dynamic_cast<HFNode<T> *>(work);
            break;
        } else if(work->key > value) {
            work = work->left;
        } else {
            work = work->right;
        }
    }
    if(ret) ret->state = RES;
    this->Fire_OnPropertyChanged("Property Changed After Find");

    if(ret == nullptr) throw ModelException("HFTree Find Failed");
    return ret;
}

template <typename T, typename S>
bool HFTree<T, S>::insert(const T& value)
{
    bool ret = true;
    content.push_back(value);
    delete this->root;
    create();
    this->Fire_OnPropertyChanged("Property Changed After Erase");
    return ret;
}

template <typename T, typename S>
void HFTree<T, S>::clear()
{
    content.clear();
    delete this->root;
    this->root = nullptr;
    this->Fire_OnPropertyChanged("Property Changed After Clear");
}

template <typename T, typename S>
bool HFTree<T, S>::erase(const T& value)
{
    bool ret = true;
    int i, size = content.size();
    for(i = 0; i < size; i++)
    {
        if (content[i] == value)
        {
            content.erase(content.begin() + i);
            delete this->root;
            if(size > 1) create();
            else this->root = nullptr;
            break;
        }
    }
    if(content.size() > 0) this->Fire_OnPropertyChanged("Property Changed After Erase");
    else this->Fire_OnPropertyChanged("Property Changed After Clear");

    if(i == size) ret = false;
    return ret;
}


template <typename T, typename S>
void HFTree<T, S>::create()
{
    int i, size = content.size();
    std::vector< HFNode<T>* > heap;
    for (i = 0; i < size; i++)
    {
        HFNode<T> * temp = new HFNode<T>(content[i]);
        heap.push_back(temp);
    }

    HFNode<T> *left, *right;
    for(i = 0; i < size - 1; i++)
    {
        find_min(heap);
        left = heap[0];
        heap.erase(heap.begin());

        find_min(heap);
        right = heap[0];
        heap.erase(heap.begin());

        HFNode<T> * parent = new HFNode<T>(left->key + right->key);
        parent->left = left;
        parent->right = right;
        heap.push_back(parent);
    }

    this->root = heap[0];

    int count = 0;
    this->inorder(this->root, &count);
    this->levelorder();
}

template <typename T>
void find_min(std::vector< HFNode<T>* > & heap)
{
    int i, min = 0, size = heap.size();

    for (i = 1; i < size; i++)
        if (heap[i]->key < heap[min]->key) min = i;

    HFNode<T>* temp = heap[0];
    heap[0] = heap[min];
    heap[min] = temp;
}

#endif
