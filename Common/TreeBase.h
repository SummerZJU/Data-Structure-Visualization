#ifndef TREEBASE_H_
#define TREEBASE_H_

#include <functional>
#include "../Model/Common.h"
#include "etlbase.h"
#include <queue>
#include <exception>
using namespace std;

template <typename T>
struct BaseNode {
	T key;
	BaseNode *left;
	BaseNode *right;

	int depth;
	int inorderIndex; 
	NodeType state;
	NodeColor color;

	BaseNode(const T& key);
	virtual ~BaseNode(); 
};

template <typename T>
BaseNode<T>::BaseNode(const T& key):
	key(key),
	left(nullptr),
	right(nullptr),
	depth(0),
	inorderIndex(0),
	state(OTHER),
	color(RED)
{

}

// root-first recurrensive dtor!
template <typename T>
BaseNode<T>::~BaseNode()
{
	if(left) delete left;
	if(right) delete right;
}

template <typename T, typename S = std::less<T>>
class BaseTree : public Proxy_PropertyNotification<BaseTree<T, S>>, 
				 public Proxy_CommandNotification<BaseTree<T, S>> {
protected:
	BaseNode<T> *root;
protected:
	void inorder(BaseNode<T> *cur, int *count);
	void levelorder();
public:
	BaseTree();
	virtual ~BaseTree();
	BaseNode<T> *getRoot();
	virtual BaseNode<T> *getNIL();
	void clear();
};

template <typename T, typename S>
BaseTree<T, S>::BaseTree():
	root(nullptr)
{

}

template <typename T, typename S>
BaseTree<T, S>::~BaseTree()
{
	if(root != nullptr) delete root;
}

template <typename T, typename S>
BaseNode<T> *BaseTree<T, S>::getRoot()
{
    try {
        return root;
    } catch(...) {
        return nullptr;
    }
}

template <typename T, typename S>
BaseNode<T> *BaseTree<T, S>::getNIL()
{
	return nullptr;
	// reimplement by RB-Tree
}

template <typename T, typename S>
void BaseTree<T, S>::inorder(BaseNode<T> *cur, int *count)
{
	if(cur != nullptr) {
		inorder(cur->left, count);
		cur->inorderIndex = (*count)++;
		inorder(cur->right, count);
	}
}

template <typename T, typename S>
void BaseTree<T, S>::levelorder()
{
	queue<BaseNode<T> *> myQueue;
	if(root) {
		root->depth = 0;
		myQueue.push(root);
		while(!myQueue.empty()) {
			BaseNode<T> *cur = myQueue.front();
			myQueue.pop();
			cur->state = OTHER;
			if(cur->left) {
				cur->left->depth = cur->depth + 1;
				myQueue.push(cur->left);
			}
			if(cur->right) {
				cur->right->depth = cur->depth + 1;
				myQueue.push(cur->right);
			}
		}
	}
}

template <typename T, typename S>
void BaseTree<T, S>::clear()
{
	if(root) delete root;
	root = nullptr;
	this->Fire_OnPropertyChanged("Property Changed After Clear");
}

#endif
