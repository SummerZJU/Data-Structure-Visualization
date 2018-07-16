#ifndef BST_H_
#define BST_H_

#include <cassert>
#include <stack>
#include <queue>
#include "Common.h"
#include <iostream>
#include "../CommonBase/TreeBase.h"

using namespace std;

#define BST_DEBUG

template<typename T>
struct BSTNode : public BaseNode<T>{
	BSTNode(const T& key);
	virtual ~BSTNode(); // auto-recursion freeTree! hahah ==!
};

template <typename T>
BSTNode<T>::BSTNode(const T& key):
	BaseNode<T>(key)
{
	// trival
}

// root-first recurrensive dtor!
template <typename T>
BSTNode<T>::~BSTNode()
{
	// trival
}

//---------------------------------------------------------------------------//
//																			 //
//																			 //
//																			 //
//																	         //
//																			 //
//---------------------------------------------------------------------------//

template <typename T, typename S = less<T>>
class BST : public BaseTree<T, S> {
	BaseNode<T> *insert(BaseNode<T> *cur, const T& key);

	void erase(BSTNode<T> *pos, BSTNode<T> *parent); // deprecated
	
	void erase(BaseNode<T> *pos);
public:
#ifdef BST_DEBUG
	void print(BaseNode<T> *cur);
	void print();
#endif
	BST();
	virtual ~BST();
	void insert(const T& key);
	BSTNode<T> *find(const T& key);
	void erase(const T& key);
};

template <typename T, typename S>
BST<T, S>::BST():
	BaseTree<T>()
{
	// trival
}

template <typename T, typename S>
BST<T, S>::~BST()
{
	//trival
}

template <typename T, typename S>
BaseNode<T> *BST<T, S>::insert(BaseNode<T> *cur, const T& key)
{
	BaseNode<T> *ret = cur;
	if(cur == nullptr) {
		BSTNode<T> *work = new BSTNode<T>(key);
		ret = work;
	} else if(cur->key < key) {
		ret->right = insert(ret->right, key);
	} else {
		ret->left = insert(ret->left, key);
	}
	// 
	// == key -> insert failed!
	//
	return ret;
}

template <typename T, typename S>
void BST<T, S>::insert(const T& key)
{
	this->root = insert(this->root, key);
	int count = 0;
	this->inorder(this->root, &count);
	this->levelorder();
}

template <typename T, typename S>
void BST<T, S>::erase(BSTNode<T> *pos, BSTNode<T> *parent)
{
	//assert(root != nullptr && pos != nullptr);
	if(this->root != nullptr && pos != nullptr) {
		BSTNode<T> *eraseFinal = pos;
		if(pos->right != nullptr && pos->left != nullptr) {
			eraseFinal = pos->left;
			parent = pos;
			while(eraseFinal->right) {
				parent = eraseFinal; 
				eraseFinal = eraseFinal->right;
			}
		}
		if(eraseFinal->right != nullptr) {
			if(parent == nullptr) {
				this->root = eraseFinal->right; // erase a root(sea node)
			} else {
				bool isLeft = parent->left == eraseFinal;
				if(isLeft) parent->left = eraseFinal->right;
				else parent->right = eraseFinal->right;
			}
		} else {
			if(parent == nullptr) {
				this->root = eraseFinal->left; // erase a root(sea node)
			} else {
				bool isLeft = parent->left == eraseFinal;
				if(isLeft) parent->left = eraseFinal->left;
				else parent->right = eraseFinal->left;
			}
		}
		eraseFinal->left = eraseFinal->right = nullptr;
		delete eraseFinal;
	}
}

template <typename T, typename S>
void BST<T, S>::erase(BaseNode<T> *pos)
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
		// at least one BSTNode in stack
		BaseNode<T> *temp = myStack.top();
		myStack.pop();

		level = temp; // at least oldRoot!!!
		if(temp->left == delPos) {
			temp->left = after;
		} else {
			temp->right = after;
		}
		delPos->left = delPos->right = nullptr;
		delete delPos;

		// level stands for top/current !
		// temp last top !
		
		while(!myStack.empty()) {
			BaseNode<T> *top = myStack.top();
			myStack.pop();
			if(top->left == temp) {
				top->left = level;
				level = top;
			} else {
				top->right = level;
				level = top;
			}
			temp = top;
		}
		this->root = level;
	}
	return;
}

template <typename T, typename S>
BSTNode<T> *BST<T, S>::find(const T& key)
{
	BSTNode<T> *ret = nullptr;
	BaseNode<T> *work = this->root;
	// reset to OTHER!
	this->levelorder(); 
	// reset to OTHER!
	while(work) {
		work->state = PATH;
		if(work->key == key) {
			ret = dynamic_cast<BSTNode<T> *>(work);
			break;
		} else if(work->key > key) {
			work = work->left;
		} else {
			work = work->right;
		}
	}
	if(ret) ret->state = RES;
	return ret;
}

template <typename T, typename S>
void BST<T, S>::erase(const T& key)
{
	BSTNode<T> *work = find(key);
	if(work != nullptr) erase(work);
	int count = 0;
	this->inorder(this->root, &count);
	this->levelorder();
}


// just for debug

#ifdef BST_DEBUG
template <typename T, typename S>
void BST<T, S>::print(BaseNode<T> *_cur)
{
	BSTNode<T> *cur = dynamic_cast<BSTNode<T> *>(_cur);
	if(cur) {
		print(cur->left);
		cout << "Key = " << cur->key << endl;
		cout << "Depth = " << cur->depth << ", inorderIndex = " << cur->inorderIndex << endl;
		cout << "left is " << (cur->left ? to_string(cur->left->key) : "nullptr") << endl;
		cout << "right is " << (cur->right ? to_string(cur->right->key) : "nullptr") << endl;
		print(cur->right);
	}
}

template <typename T, typename S>
void BST<T, S>::print()
{
	print(this->root);
	return;
}
#endif

#endif
