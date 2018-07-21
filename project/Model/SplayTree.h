#ifndef SPT_H_
#define SPT_H_

#include <assert.h>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include "../Common/Common.h"
#include "../Common/TreeBase.h"
#include "../Common/Exception/ModelException.h"
using namespace std;

#define SPT_DEBUG

template <typename T>
struct SPTNode : BaseNode<T> {
	BaseNode<T> *parent;
		
	SPTNode(const T& key, BaseNode<T> *parent);
	virtual ~SPTNode();

	// this == parent
	SPTNode *RR();
	SPTNode *LL();

	// this == grandfa + grandma
	SPTNode *zig_zig(SPTNode *pos); // this->root -> new this->root
	SPTNode *zig_zag(SPTNode *pos); // grand is this; pos is child!
};


//-----------------------------------------------------------------------//
//SplayTreeNode(SPTNode) declaration

template <typename T>
SPTNode<T>::SPTNode(const T& key, BaseNode<T> *parent):
	BaseNode<T>(key),
	parent(parent)
{
	if(parent) this->depth = parent->depth + 1;
}

template <typename T>
SPTNode<T>::~SPTNode()
{
	// trival is here
	// BaseNode is enough
}

template <typename T>
SPTNode<T> *SPTNode<T>::LL()
{
	BaseNode<T> *temp = this->left;
	this->left = temp->right;
	if(temp->right) dynamic_cast<SPTNode<T> *>(temp->right)->parent = this;
	temp->right = this;
	parent = temp;

	return dynamic_cast<SPTNode<T> *>(temp);
}

template <typename T>
SPTNode<T> *SPTNode<T>::RR()
{
	BaseNode<T> *temp = this->right;
	this->right = temp->left;
	if(temp->left) dynamic_cast<SPTNode<T> *>(temp->left)->parent = this;
	temp->left = this;
	parent = temp;

	return dynamic_cast<SPTNode<T> *>(temp);
}

template <typename T>
SPTNode<T> *SPTNode<T>::zig_zig(SPTNode *pos)
{
	SPTNode<T> *ret = nullptr;
	if(this->left && this->left->left == pos) {
		SPTNode<T> *temp = LL();
		ret = temp->LL();
	} else if(this->right && this->right->right == pos) {
		SPTNode<T> *temp = RR();
		ret = temp->RR();
	}
	return ret;
}

template <typename T>
SPTNode<T> *SPTNode<T>::zig_zag(SPTNode *pos)
{
	SPTNode<T> *ret = nullptr;
	if(this->left && this->left->right == pos) {
		SPTNode *temp = dynamic_cast<SPTNode<T> *>(this->left)->RR();
		temp->parent = this;
		this->left = temp;
		ret = LL();
	} else if (this->right && this->right->left == pos) {
		SPTNode *temp = dynamic_cast<SPTNode<T> *>(this->right)->LL();
		temp->parent = this;
		this->right = temp;
		ret = RR();
	}  

	return ret;
}

//---------------------------------------------------------------------------//
//																			 //
//																			 //
//																			 //
//																	         //
//																			 //
//---------------------------------------------------------------------------//


template <typename T, typename S = less<T>>
class SplayTree : public BaseTree<T, S>{
	void fixup(SPTNode<T> *pos);           // after finding or inserting
	BaseNode<T> *insert(const T& key, BaseNode<T> *father, BaseNode<T> *pos); // for recurssion
	void erase(BaseNode<T> *pos);
public:
#ifdef SPT_DEBUG
	void print() const;
#endif
	SplayTree();
	virtual ~SplayTree();
	SPTNode<T> *find(const T& key);        // return this->root; const member func is naive!!!
	void insert(const T& key);
	void insert_recursion(const T& key);
	void erase(const T& key);
};
//--------------------------------------------------------------------------//
//SplayTree declaration

template <typename T, typename S>
SplayTree<T, S>::SplayTree():
	BaseTree<T, S>()
{
	// trival
}

template <typename T, typename S>
SplayTree<T, S>::~SplayTree()
{
	// trival
}


template <typename T, typename S>
void SplayTree<T, S>::fixup(SPTNode<T> *pos)
{
	while(pos->parent) {
		if(dynamic_cast<SPTNode<T> *>(pos->parent)->parent) {
			SPTNode<T> *p = dynamic_cast<SPTNode<T> *>(pos->parent);
			SPTNode<T> *g = dynamic_cast<SPTNode<T> *>(p->parent);
			SPTNode<T> *temp = dynamic_cast<SPTNode<T> *>(g->parent);
			int isLeft;
			if(temp) isLeft = temp->left == g;
			if(g->left == p && p->left == pos || 
			   g->right == p && p->right == pos) {
				pos = g->zig_zig(pos);
				pos->parent = temp; // nullptr / non-nullptr
				if(temp) {
					if(isLeft) temp->left = pos;
					else temp->right = pos;
				}
			} else {
				pos = g->zig_zag(pos);
				pos->parent = temp;
				if(temp) {
					if(isLeft) temp->left = pos;
					else temp->right = pos;
				}
			}
		} else {
			if (pos->parent->left == pos) {
				pos = dynamic_cast<SPTNode<T> *>(pos->parent)->LL();
				pos->parent = nullptr;
			} else {
				pos = dynamic_cast<SPTNode<T> *>(pos->parent)->RR();
				pos->parent = nullptr;
			}
		}
	}	
	this->root = pos;

	return;
}

template <typename T, typename S>
SPTNode<T> *SplayTree<T, S>::find(const T& key)
{
	SPTNode<T> *ret = nullptr;
	BaseNode<T> *work = this->root;
	// reset to OTHER!
	this->levelorder(); 
	// reset to OTHER!
	while(work) {
		work->state = PATH;
		if(work->key == key) {
			ret = dynamic_cast<SPTNode<T> *>(work);
			break;
		} else if(work->key > key) {
			work = work->left;
		} else {
			work = work->right;
		}
	}
	// this->root->parent == nullptr
	if(ret) {
		ret->state = RES;
		fixup(ret);
        int count = 0;
        this->inorder(this->root, &count);
        this->levelorder();
        ret->state = RES;  // reset by levelorder()
	}
	this->Fire_OnPropertyChanged("Property Changed After Find");
	if(ret == nullptr) throw ModelException("SplayTree Find Failed");
	return ret; // nullptr / has been set this->root
}

template <typename T, typename S>
BaseNode<T> *SplayTree<T, S>::insert(const T& key, BaseNode<T> *father, BaseNode<T> *pos)
{
	SPTNode<T> *ret = pos;
	if(!ret) {
		ret = new SPTNode<T>(key, father);
	} else if(pos->key > key) {
		ret->left = insert(key, ret, ret->left);
	} else if(pos->key < key){
		ret->right = insert(key, ret, ret->right);
	} else {
		throw ModelException("SplayTree Inset Failed");
	}

	return ret;
}

template <typename T, typename S>
void SplayTree<T, S>::insert_recursion(const T& key)
{
	this->root = insert(key, nullptr, this->root);
	find(key);

	int count = 0;
	this->inorder(this->root, &count);
	this->levelorder();

	this->Fire_OnPropertyChanged("Property Changed After Insert");
	return;
}

template <typename T, typename S>
void SplayTree<T, S>::insert(const T& key)
{
	BaseNode<T> *work = this->root;
	SPTNode<T> *last = nullptr;
	int isLeft = -1;
	while(work) {
		last = dynamic_cast<SPTNode<T> *>(work);
		if(work->key > key) {
			work = work->left;
			isLeft = 1;
		} else if(work->key < key) {
			work = work->right;
			isLeft = 0;
		} else {
			throw ModelException("SplayTree Insert Failed");
		}
	}
	if(!last) {
		this->root = new SPTNode<T>(key, nullptr);
	} else if(isLeft){
		last->left = new SPTNode<T>(key, last);
		fixup(dynamic_cast<SPTNode<T> *>(last->left));
	} else {
		last->right = new SPTNode<T>(key, last);
		fixup(dynamic_cast<SPTNode<T> *>(last->right));
	}

	int count = 0;
	this->inorder(this->root, &count);
	this->levelorder();
	this->Fire_OnPropertyChanged("Property Changed After Insert");
}

template <typename T, typename S>
void SplayTree<T, S>::erase(BaseNode<T> *pos)
{
	assert(pos);
	if(pos->left && pos->right) {
		BaseNode<T> *temp = pos->left;
		while(temp->right) temp = temp->right;
		pos->key = temp->key;
		pos = temp;
	}
	BaseNode<T> *parent = dynamic_cast<SPTNode<T> *>(pos)->parent;
	int isLeft;
	if(parent) isLeft = parent->left == pos;
	if(pos->left) {
		if(!parent) {
			this->root = pos->left;
			if(this->root) dynamic_cast<SPTNode<T> *>(this->root)->parent = nullptr;
		} else if(isLeft) {
			parent->left = pos->left;
			if(pos->left) dynamic_cast<SPTNode<T> *>(pos->left)->parent = parent;
		} else {
			parent->right = pos->left;
			if(pos->left) dynamic_cast<SPTNode<T> *>(pos->left)->parent = parent;
		}
	} else {
		if(!parent) {
			this->root = pos->right;
			if(this->root) dynamic_cast<SPTNode<T> *>(this->root)->parent = nullptr;
		} else if(isLeft) {
			parent->left = pos->right;
			if(pos->right) dynamic_cast<SPTNode<T> *>(pos->right)->parent = parent;
		} else {
			parent->right = pos->right;
			if(pos->right) dynamic_cast<SPTNode<T> *>(pos->right)->parent = parent;
		}		
	}
	pos->left = pos->right = nullptr;
	delete pos;
	return;
}

template <typename T, typename S>
void SplayTree<T, S>::erase(const T& key)
{
	bool res = true;
	try {	
		SPTNode<T> *temp = find(key);
		if(temp) erase(temp);
	
		int count = 0;
		this->inorder(this->root, &count);
		this->levelorder();
	} catch(const exception& e) {
		e.what();
		res = false;
	}
	this->Fire_OnPropertyChanged("Property Changed After Erase");
	if(!res) throw ModelException("SplayTree Erase Failed");
	return;
}


#ifdef SPT_DEBUG
template <typename T, typename S>
void SplayTree<T, S>::print() const
{
	typedef BaseNode<T> *Entry;
	stack<Entry> myStack;
	Entry work = this->root;
	while(true) {
		for(; work; work = work->left) {
			myStack.push(work);
		}
		if(myStack.empty()) break;
		Entry top = myStack.top();
		myStack.pop();
		cout << "Key: " << top->key << endl;
		cout << "left: ";
		if(top->left) cout << top->left->key << ' ';
		else cout << "nullptr ";
		cout << "right: ";
		if(top->right) cout << top->right->key << endl;
		else cout << "nullptr" << endl;
		work = top->right;
	}
	return;
}
#endif

#endif
