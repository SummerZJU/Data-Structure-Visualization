
#ifndef RBT_H_
#define RBT_H_

#include <cassert>
#include <stack>
#include <queue>
#include "Common.h"
#include <iostream>
#include "../Common/TreeBase.h"
#include "../Common/Exception/ModelException.h"
#include <exception>

#define RBT_DEBUG

using namespace std;

template <typename T>
struct RBTNode : public BaseNode<T> {
	BaseNode<T> *parent;
	RBTNode(const T& key);
	virtual ~RBTNode();
};

template <typename T>
RBTNode<T>::RBTNode(const T& key):
	BaseNode<T>(key),
	parent(nullptr)
{

}

template <typename T>
RBTNode<T>::~RBTNode()
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
class RBT : public BaseTree<T, S> {
	BaseNode<T> *LL(BaseNode<T> *NIL, BaseNode<T> *pivot);
	BaseNode<T> *RR(BaseNode<T> *NIL, BaseNode<T> *pivot); // pivot is povit

	BaseNode<T> *insert(BaseNode<T> *oRoot, const T& key);
	RBTNode<T> *insertFixup(RBTNode<T> *newRoot, RBTNode<T> *current);

	RBTNode<T> *find(const T& key, BaseNode<T> *NIL);

	BaseNode<T> *erase(BaseNode<T> *oRoot, BaseNode<T> *pos);
	RBTNode<T> *eraseFixup(RBTNode<T> *newRoot, RBTNode<T> *x);

	void inorder(BaseNode<T> *cur, int *count, BaseNode<T> *NIL);
	void levelorder(BaseNode<T> *NIL);
	void clear(BaseNode<T> *cur, BaseNode<T> *NIL);
public:	
#ifdef RBT_DEBUG
	void print(BaseNode<T> *cur, BaseNode<T> *NIL);
	void print();
#endif	
	RBT();
	virtual ~RBT();
	void insert(const T& key);
	RBTNode<T> *find(const T& key);
	void erase(const T& key);
	void clear();
};

template <typename T, typename S>
RBT<T, S>::RBT():
	BaseTree<T, S>()
{
	// to-do
	// RBT require a empty black root
	// int == 0

	// bad/dirty design //
	// 
	//
	// bad/dirty design //
	this->root = new RBTNode<T>(0);
	this->root->color = BLACK;
}

template <typename T, typename S>
RBT<T, S>::~RBT()
{
	BaseNode<T> *NIL = dynamic_cast<RBTNode<T> *>(this->root)->parent;
	clear();							// leave out a NIL
	this->root = nullptr;               // make base-dtor trival
	NIL->left = NIL->right = nullptr;
	delete NIL;							// prevent recurrsion!

}

template <typename T, typename S>
BaseNode<T> *RBT<T, S>::LL(BaseNode<T> *NIL, BaseNode<T> *pivot)
{
	BaseNode<T> *temp = pivot->left;
	pivot->left = temp->right;
	if(temp->right != NIL) dynamic_cast<RBTNode<T> *>(temp->right)->parent = pivot;
	temp->right = pivot;
	dynamic_cast<RBTNode<T> *>(pivot)->parent = temp;

	return temp; // new root
}

template <typename T, typename S>
BaseNode<T> *RBT<T, S>::RR(BaseNode<T> *NIL, BaseNode<T> *pivot)
{
	BaseNode<T> *temp = pivot->right;
	pivot->right = temp->left;
	if(temp->left != NIL) dynamic_cast<RBTNode<T> *>(temp->left)->parent = pivot;
	temp->left = pivot;
	dynamic_cast<RBTNode<T> *>(pivot)->parent = temp;

	return temp;
}

////////////////////////////////////////////////////////////
// !!! ??? !!!
// NIL Node will be initilized while inserting first key
// !!! ??? !!!
////////////////////////////////////////////////////////////
// root is root
// return must be new root
// @NOTE: local root == this->root
// here is copied from xiaoqiang2018WinterProgram

template <typename T, typename S>
BaseNode<T> *RBT<T, S>::insert(BaseNode<T> *oRoot, const T& key)
{
	BaseNode<T> *ret = oRoot;
	
	RBTNode<T> *current = new RBTNode<T>(key);
	// default RED

	if(dynamic_cast<RBTNode<T> *>(oRoot)->parent == nullptr) { // oRoot == dummy
		ret = current;
		current->parent = oRoot; // dummy
		current->left = current->right = oRoot;
	} else { 
		//non-nullptr stand for oRoot->parent is dummy
		current->left = current->right = dynamic_cast<RBTNode<T> *>(oRoot)->parent;
		BaseNode<T> *work = oRoot, *temp = nullptr;
		while(work != dynamic_cast<RBTNode<T> *>(oRoot)->parent) {
			temp = work;
			if(key > work->key)
				work = work->right;
			else if(key < work-> key)
				work = work->left;
			else
				throw ModelException("RBT Insert Failed");
		}
		current->parent = temp;
		if(temp->key > key) {
			temp->left = current;
		} else {
			temp->right = current;
		}
	}
	ret = insertFixup(dynamic_cast<RBTNode<T> *>(ret), current);
	return ret;	
}

// @parameter : new root(after insert)
// @return : new root(after insertFixup)
template <typename T, typename S>
RBTNode<T> *RBT<T, S>::insertFixup(RBTNode<T> *newRoot, RBTNode<T> *current)
{
	RBTNode<T> *ret = newRoot;
	while(current->parent->color == RED) {
		BaseNode<T> *grandPa = dynamic_cast<RBTNode<T> *>(current->parent)->parent;
		BaseNode<T> *uncle;
		if(grandPa->right == current->parent) {
			uncle = grandPa->left;
			if(uncle->color == RED) {
				current->parent->color = uncle->color = BLACK;
				grandPa->color = RED;
				current = dynamic_cast<RBTNode<T> *>(grandPa);
			} else {
				if(current->parent->left == current) {
					BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(current->parent)->parent;
					current = dynamic_cast<RBTNode<T> *>(current->parent);
					RBTNode<T> *newRoot = dynamic_cast<RBTNode<T> *>(LL(ret->parent, current));
					temp->right = newRoot;
					newRoot->parent = temp->right;
				}
				current->parent->color = BLACK;
				grandPa->color = RED;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(grandPa)->parent;
				if(grandPa == ret) {
					ret = dynamic_cast<RBTNode<T> *>(RR(ret->parent, grandPa));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == grandPa;
					RBTNode<T> *newRoot = dynamic_cast<RBTNode<T> *>(RR(ret->parent, grandPa));
					newRoot->parent = temp;
					if(isLeft)
						temp->left = newRoot;
					else
						temp->right = newRoot;
				}

			}
		} else {
			uncle = grandPa->right;
			if(uncle->color == RED) {
				current->parent->color = uncle->color = BLACK;
				grandPa->color = RED;
				current = dynamic_cast<RBTNode<T> *>(grandPa);
			} else {
				if(current->parent->right == current) {
					BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(current->parent)->parent;
					current = dynamic_cast<RBTNode<T> *>(current->parent);
					RBTNode<T> *newRoot = dynamic_cast<RBTNode<T> *>(RR(ret->parent, current));
					temp->left = newRoot;
					newRoot->parent = temp->left;
				}
				current->parent->color = BLACK;
				grandPa->color = RED;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(grandPa)->parent;
				if(grandPa == ret) {
					ret = dynamic_cast<RBTNode<T> *>(LL(ret->parent, grandPa));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == grandPa;
					RBTNode<T> *newRoot = dynamic_cast<RBTNode<T> *>(LL(ret->parent, grandPa));
					newRoot->parent = temp;
					if(isLeft)
						temp->left = newRoot;
					else
						temp->right = newRoot;
				}
				
			}
		}
	}
	ret->color = BLACK; /* jumping two level newRoot == RED -> newRoot->parent == BLACK*/
	return ret;
}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::find(const T& key, BaseNode<T> *NIL)
{
	RBTNode<T> *ret = nullptr;
	BaseNode<T> *work = this->root;
	// reset to OTHER!
	this->levelorder(dynamic_cast<RBTNode<T> *>(this->root)->parent);
	// reset to OTHER!
	while(work != NIL) {
		work->state = PATH;
		if(work->key == key) {
			ret = dynamic_cast<RBTNode<T> *>(work);
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
BaseNode<T> *RBT<T, S>::erase(BaseNode<T> *oRoot, BaseNode<T> *pos)
{
	RBTNode<T> *ret = dynamic_cast<RBTNode<T> *>(oRoot);
	RBTNode<T> *temp = dynamic_cast<RBTNode<T> *>(pos);
	RBTNode<T> *x = nullptr; // truely Erase (sea node!)
	if(pos->left != ret->parent && pos->right != ret->parent) {
		BaseNode<T> *work = pos->left;
		while(work->right != ret->parent) work = work->right;
		temp = dynamic_cast<RBTNode<T> *>(work);
		pos->key = temp->key;
	}
	if(temp->left != ret->parent) x = dynamic_cast<RBTNode<T> *>(temp->left);
	else x = dynamic_cast<RBTNode<T> *>(temp->right);
	x->parent = temp->parent;	
	/*
		temp为oRoot时，x为一般儿子 -> x为oRoot（oRoot->parent == dummy）
				     x为dummy    ->   树空， ret == x == dummy, dummy->parent == dummy 
		temp为一般时， temp已经孤立（以上也是）
	*/
	/*以上使用旧根oRoot即可， 跟新ret后要使用新根ret*/
	if(temp->parent == ret->parent) {
		ret = x;
	} else { 
		// x仍可能为dummy， 双重黑
		if(temp->parent->left == temp)
			temp->parent->left = x;
		else
			temp->parent->right = x;
	}
	if(temp->color == BLACK)       // oRoot must be BLACK, 
		ret = eraseFixup(ret, x);  // ret <==> newRoot 
	                               // ret == x: 新上来的 or dummy == dummy
	temp->left = temp->right = nullptr;
	delete temp;
	return ret;
}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::eraseFixup(RBTNode<T> *newRoot, RBTNode<T> *x)
{
	RBTNode<T> *ret = newRoot;
	while(ret != x && x->color == BLACK) {
		if(x->parent->left == x) {
			BaseNode<T> *w = x->parent->right;
			//case1: w is RED, must be two's BLACK, swap color, RR-rotation()
			if(w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(x->parent)->parent;
				//x->parent is the newRoot!
				if(temp == ret->parent) {
					ret = dynamic_cast<RBTNode<T> *>(RR(ret->parent, x->parent));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(RR(ret->parent, x->parent));
					newTree->parent = temp;
					if(isLeft)
						temp->left = newTree;
					else
						temp->right = newTree;
				}
				w = x->parent->right;
			}
			//case2: w is BLACK, have two  BLACK child(two dummy)
			if(w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = dynamic_cast<RBTNode<T> *>(x->parent);
			} else {
				//case3: w is BLACK, left is RED, right is BLACK
				//w, w->left swap color, LL-rotation()
				if(w->right->color == BLACK) {
					w->color = RED;
					w->left->color = BLACK;
					BaseNode<T> *xParent = x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(LL(ret->parent, w));
					newTree->parent = xParent;
					xParent->right = newTree;
					w = newTree;
				}
				//case4: w is BLACK, right is RED
				//w->color: x->parent->color
				//x->parent->color: BLACK
				//w->right->color: BLACK RR-rotation(x->parent)
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(x->parent)->parent;
				if(temp == ret->parent) {
					ret = dynamic_cast<RBTNode<T> *>(RR(ret->parent, x->parent));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(RR(ret->parent, x->parent));
					newTree->parent = temp;
					if(isLeft)
						temp->left = newTree;
					else
						temp->right = newTree;
				}
				x = ret; // set root -> over eraseFixup
			}
		} else {
			BaseNode<T> *w = x->parent->left;
			//case1: w is RED, must be two's BLACK, swap color, RR-rotation()
			if(w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(x->parent)->parent;
				if(temp == ret->parent) {
					ret = dynamic_cast<RBTNode<T> *>(LL(ret->parent, x->parent));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(LL(ret->parent, x->parent));
					newTree->parent = temp;
					if(isLeft)
						temp->left = newTree;
					else
						temp->right = newTree;
				}
				w = x->parent->left;
			}
			//case2: w is BLACK, have two  BLACK child(two dummy)
			if(w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = dynamic_cast<RBTNode<T> *>(x->parent);
			} else {
				//case3: w is BLACK, left is RED, right is BLACK
				//w, w->left swap color, LL-rotation()
				if(w->left->color == BLACK) {
					w->color = RED;
					w->right->color = BLACK;
					BaseNode<T> *xParent = x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(RR(ret->parent, w));
					newTree->parent = xParent;
					xParent->left = newTree;
					w = newTree;
				}
				//case4: w is BLACK, right is RED
				//w->color: x->parent->color
				//x->parent->color: BLACK
				//x->right->color: BLACK RR-rotation(x->parent)
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				BaseNode<T> *temp = dynamic_cast<RBTNode<T> *>(x->parent)->parent;
				if(temp == ret->parent) {
					ret = dynamic_cast<RBTNode<T> *>(LL(ret->parent, x->parent));
					ret->parent = temp;
				} else {
					int isLeft = temp->left == x->parent;
					RBTNode<T> *newTree = dynamic_cast<RBTNode<T> *>(LL(ret->parent, x->parent));
					newTree->parent = temp;
					if(isLeft)
						temp->left = newTree;
					else
						temp->right = newTree;
				}
				x = ret;
			}
		}
	}
	x->color = BLACK; // newRoot == dummy && x == dummy
	                  // 双重黑根 only when after erase conflict 2-rule!
	                  // 红黑（newRoot or non-root）
	return ret;
}

template <typename T, typename S>
void RBT<T, S>::insert(const T& key)
{
	this->root = insert(this->root, key);
	int count = 0;
	this->inorder(this->root, &count, dynamic_cast<RBTNode<T> *>(this->root)->parent);
	this->levelorder(dynamic_cast<RBTNode<T> *>(this->root)->parent);

	this->Fire_OnPropertyChanged("Property Changed After Insert");
	return;
}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::find(const T& key)
{
	RBTNode<T> *ret = find(key, dynamic_cast<RBTNode<T> *>(this->root)->parent);
	this->Fire_OnPropertyChanged("Property Changed After Find");

	if(ret == nullptr) throw ModelException("RBT Find Failed");
	return ret;
}

template <typename T, typename S>
void RBT<T, S>::erase(const T& key)
{
	bool res = true;
	try {
		auto work = find(key);
		if(work != nullptr) this->root = erase(this->root, work);
		int count = 0;
		this->inorder(this->root, &count, dynamic_cast<RBTNode<T> *>(this->root)->parent);
		this->levelorder(dynamic_cast<RBTNode<T> *>(this->root)->parent);		
	} catch(const exception& e) {
		e.what();
		res = false;
	}

	this->Fire_OnPropertyChanged("Property Changed After Erase");
	if(!res) throw ModelException("RBT Erase Failed");
	return;
}

template <typename T, typename S>
void RBT<T, S>::inorder(BaseNode<T> *cur, int *count, BaseNode<T> *NIL)
{
	if(cur != NIL) {
		inorder(cur->left, count, NIL);
		cur->inorderIndex = (*count)++;
		inorder(cur->right, count, NIL);
	}
}

template <typename T, typename S>
void RBT<T, S>::levelorder(BaseNode<T> *NIL)
{
	queue<BaseNode<T> *> myQueue;
	if(this->root != NIL) {
		this->root->depth = 0;
		myQueue.push(this->root);
		while(!myQueue.empty()) {
			BaseNode<T> *cur = myQueue.front();
			myQueue.pop();
			cur->state = OTHER;
			if(cur->left != NIL) {
				cur->left->depth = cur->depth + 1;
				myQueue.push(cur->left);
			}
			if(cur->right != NIL) {
				cur->right->depth = cur->depth + 1;
				myQueue.push(cur->right);
			}
		}
	}
}

template <typename T, typename S>
void RBT<T, S>::clear(BaseNode<T> *cur, BaseNode<T> *NIL)
{
	if(cur != NIL) {
		clear(cur->left, NIL);
		clear(cur->right, NIL);
		cur->left = cur->right = nullptr;
		delete cur;                      // prevent recurrsion!!!
	}
}

template <typename T, typename S>
void RBT<T, S>::clear()
{
	RBTNode<T> *NIL = dynamic_cast<RBTNode<T> *>(dynamic_cast<RBTNode<T> *>(this->root)->parent);
	clear(this->root, NIL);
	NIL->parent = NIL->left = NIL->right = nullptr;
	NIL->parent = NIL;                  // empty RB-Tree & leave out a NIL
}

#ifdef RBT_DEBUG

template <typename T, typename S>
void RBT<T, S>::print(BaseNode<T> *_cur, BaseNode<T> *NIL)
{
	RBTNode<T> *cur = dynamic_cast<RBTNode<T> *>(_cur);
	if(cur != NIL) {
		print(cur->left, NIL);
		cout << "Key = " << cur->key << ", color = " 
		     << (cur->color == RED ? "RED" : "BLACK") << endl;
		cout << "Depth = " << cur->depth << ", inorderIndex = " << cur->inorderIndex << endl;
		cout << "left is " << (cur->left ? to_string(cur->left->key) : "nullptr") << endl;
		cout << "right is " << (cur->right ? to_string(cur->right->key) : "nullptr") << endl;
		print(cur->right, NIL);
	}
}

template <typename T, typename S>
void RBT<T, S>::print()
{
	print(this->root, dynamic_cast<RBTNode<T> *>(this->root)->parent);
}

#endif

#endif