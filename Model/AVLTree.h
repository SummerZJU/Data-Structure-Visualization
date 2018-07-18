#ifndef _AVL_H_
#define _AVL_H_
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <exception>
#include "Common.h"
#include "../Common/TreeBase.h"
#include "../Common/Exception/ModelException.h"
using namespace std;

#define AVL_DEBUG

// template inherit template(ont to one)
template<typename T>
struct AVLNode : public BaseNode<T>{
	int height;

	AVLNode(const T& key);
	~AVLNode(); // auto-recursion freeTree! hahah ==!
};

// template inherit template(one to one)
template<typename T, typename S = less<T>>
class AVLTree : public BaseTree<T, S> {	
	// root is a BaseNode 
	// pointer is a member of BaseTree
	int getHeight(BaseNode<T> *_pos);
	BaseNode<T> *RR(BaseNode<T> *pos);
	BaseNode<T> *LL(BaseNode<T> *pos);
	BaseNode<T> *RL(BaseNode<T> *pos);
	BaseNode<T> *LR(BaseNode<T> *pos);
	void erase(BaseNode<T> *pos);
	BaseNode<T> *insert(BaseNode<T> *pos, const T& key); //recurson for implementation
public:
#ifdef AVL_DEBUG
	void print(BaseNode<T> *cur);
	void print();
#endif
	AVLTree();
	virtual ~AVLTree();
	void insert(const T& key);	
	void erase(const T& key);
	AVLNode<T> *find(const T& key);
};

//------------------------------------------------------------------------------//
//AVLNode template declaration
template <typename T>
AVLNode<T>::AVLNode(const T& key):
	BaseNode<T>(key),
	height(0)
{

}

// root-first recurrensive dtor!
template <typename T>
AVLNode<T>::~AVLNode()
{
	// trival is here
	// BaseNode dtor is OK!
}
//---------------------------------------------------------------------------//
//																			 //
//																			 //
//																			 //
//																	         //
//																			 //
//---------------------------------------------------------------------------//
//AVLTree template declaration
template <typename T, typename S>
AVLTree<T, S>::AVLTree():
	BaseTree<T, S>()
{

}

template <typename T, typename S>
AVLTree<T, S>::~AVLTree()
{
	// here is trival 
	// actual action is in BaseTree
}

template<typename T, typename S>
int AVLTree<T, S>::getHeight(BaseNode<T> *_pos)
{
	AVLNode<T> *pos = dynamic_cast<AVLNode<T> *>(_pos);
	if(!pos) {
		return -1;
	} else {
		int lHeight = getHeight(pos->left);
		int rHeight = getHeight(pos->right);
		pos->height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
		return pos->height;
	}
}

template<typename T, typename S>
BaseNode<T> *AVLTree<T, S>::RR(BaseNode<T> *pos)
{
	BaseNode<T> *temp = pos->right;
	pos->right = temp->left;
	temp->left = pos;

	return temp;
}

template<typename T, typename S>
BaseNode<T> *AVLTree<T, S>::LL(BaseNode<T> *pos)
{
	BaseNode<T> *temp = pos->left;
	pos->left = temp->right;
	temp->right = pos;

	return temp;
}

template<typename T, typename S>
BaseNode<T> *AVLTree<T, S>::RL(BaseNode<T> *pos)
{
	pos->right = LL(pos->right);
	return RR(pos);
}

template<typename T, typename S>
BaseNode<T> *AVLTree<T, S>::LR(BaseNode<T> *pos)
{
	pos->left = RR(pos->left);
	return LL(pos);
}
// root
template<typename T, typename S>
BaseNode<T> *AVLTree<T, S>::insert(BaseNode<T> *pos, const T& key)
{
	BaseNode<T> *ret = pos;
	if(this->root) {
		if(!pos) {
			AVLNode<T> *cur = new AVLNode<T>(key);
			ret = cur;
		} else if(pos->key > key) {
			pos->left = insert(pos->left, key);
			if(getHeight(pos->left) - getHeight(pos->right) > 1) {
				if(key > pos->left->key) {
					ret = LR(pos);
				} else {
					ret = LL(pos);
				}
			}
        } else if(pos->key < key) {
			pos->right = insert(pos->right, key);
			if(getHeight(pos->right) - getHeight(pos->left) > 1) {
				if(key < pos->right->key) {
					ret = RL(pos);
				} else {
					ret = RR(pos);
				}
			}
        } else {
            throw ModelException("AVLTree Insert Failed");
        }
		dynamic_cast<AVLNode<T> *>(ret)->height = getHeight(ret);
	} else {
		AVLNode<T> *cur = new AVLNode<T>(key);
		this->root = cur;
		ret = cur;
	}
	return ret;
}

template <typename T, typename S>
void AVLTree<T, S>::insert(const T& key)
{

    this->root = insert(dynamic_cast<AVLNode<T> *>(this->root), key);
    int count = 0;
    this->inorder(this->root, &count);
    this->levelorder();

    this->Fire_OnPropertyChanged("Property Changed After Insert");
	return;
}

// assume pos != nullptr
template <typename T, typename S>
void AVLTree<T, S>::erase(BaseNode<T> *pos)
{
	stack<BaseNode<T> *> myStack;
	BaseNode<T> *work = this->root;
	while(work->key != pos->key) {
		myStack.push(work);
		if(work->key > pos->key) {
			work = work->left;
		} else {
			work = work->right;
		}
	} // pos is not inStack()
	BaseNode<T> *delPos = pos;
	if(pos->right && pos->left) {
		myStack.push(pos);
		delPos = pos->left;
		while(delPos->right) {
			myStack.push(delPos);
			delPos = delPos->right;
		}
		pos->key = delPos->key;
	}
	BaseNode<T> *after = delPos->right ? delPos->right : delPos->left, *level;
	if(delPos == this->root) {
		this->root = after; // maybe nullptr;
	} else {
		// at least one AVLNode in stack
		BaseNode<T> *temp = myStack.top();
		myStack.pop();

		level = temp; // at least oldRoot!!!
		if(temp->left == delPos) {
			temp->left = after;
			if(getHeight(temp->right) - getHeight(temp->left) > 1) {
				//int rlHeight = temp->right == nullptr ? -1 : 
				if(getHeight(temp->right->left) > getHeight(temp->right->right)) {
					level = RL(temp);
				} else {
					level = RR(temp);
				}
			}
		} else {
			temp->right = after;
			if(getHeight(temp->left) - getHeight(temp->right) > 1) {
				if(getHeight(temp->left->right) > getHeight(temp->left->left)) {
					level = LR(temp);
				} else {
					level = LL(temp);
				}
			}
		}
		dynamic_cast<AVLNode<T> *>(level)->height = getHeight(level);
		delPos->left = delPos->right = nullptr;
		delete delPos;

		while(!myStack.empty()) {
			BaseNode<T> *top = myStack.top();
			myStack.pop();
			if(top->left == temp) {
				top->left = level;
				level = top;
				if(getHeight(top->right) - getHeight(top->left) > 1) {
					if(getHeight(top->right->left) > getHeight(top->right->right)) {
						level = RL(top);
					} else {
						level = RR(top);
					}
				}
			} else {
				top->right = level;
				level = top;
				if(getHeight(top->left) - getHeight(top->right) > 1) {
					if(getHeight(top->left->right) > getHeight(top->left->left)) {
						level = LR(top);
					} else {
						level = LL(top);
					}
				}
			}
			temp = top;
			dynamic_cast<AVLNode<T> *>(level)->height = getHeight(level);
		}
		this->root = level;
	}
	return;
}

template <typename T, typename S>
AVLNode<T> *AVLTree<T, S>::find(const T& key)
{
	AVLNode<T> *ret = nullptr;
	BaseNode<T> *work = this->root;
	// reset to OTHER!
	this->levelorder(); 
	// reset to OTHER!
	while(work) {
		work->state = PATH;
		if(work->key == key) {
			ret = dynamic_cast<AVLNode<T> *>(work);
			break;
		} else if(work->key > key) {
			work = work->left;
		} else {
			work = work->right;
		}
	}
	if(ret) ret->state = RES;
    this->Fire_OnPropertyChanged("Property Changed After Find");
    if(ret == nullptr) throw ModelException("AVLTree Find Failed");
	return ret;
}

template <typename T, typename S>
void AVLTree<T, S>::erase(const T& key)
{
    bool res = true;
    try {
        AVLNode<T> *work = find(key);
        if(work != nullptr) erase(work);
        int count = 0;
        this->inorder(this->root, &count);
        this->levelorder();
    } catch(const exception& e) {
        res = false;
    }
    if(!res) throw ModelException("AVLTree Erase Failed");
}


// just for debug

#ifdef AVL_DEBUG
template <typename T, typename S>
void AVLTree<T, S>::print(BaseNode<T> *_cur)
{
	AVLNode<T> *cur = dynamic_cast<AVLNode<T> *>(_cur);
	if(cur) {
		print(cur->left);
		cout << "Key = " << cur->key << ", Height = " << cur->height << endl;
		cout << "Depth = " << cur->depth << ", inorderIndex = " << cur->inorderIndex << endl;
		cout << "left is " << (cur->left ? to_string(cur->left->key) : "nullptr") << endl;
		cout << "right is " << (cur->right ? to_string(cur->right->key) : "nullptr") << endl;
		print(cur->right);
	}
}

template <typename T, typename S>
void AVLTree<T, S>::print()
{
	print(dynamic_cast<AVLNode<T> *>(this->root));
	return;
}
#endif

#endif
