#ifndef SPT_H_
#define SPT_H_

#include <assert.h>
#include <iostream>
#include <stack>
#include <queue>
#include "Common.h"
using namespace std;

#define SPT_DEBUG

template <typename T>
struct SPTNode {
	T key;
	SPTNode *left;
	SPTNode *right;
	SPTNode *parent;
		
	int depth;
	int inorderIndex;  //from 0 -> ...
	NodeType state;

	SPTNode();
	SPTNode(const T& key, SPTNode *parent);
	virtual ~SPTNode();

	// this == parent
	SPTNode *RR();
	SPTNode *LL();

	// this == grandfa + grandma
	SPTNode *zig_zig(SPTNode *pos); // root -> new root
	SPTNode *zig_zag(SPTNode *pos); // grand is this; pos is child!
	void setOTHER();
	void setPATH();
	void setRES();
};

template <typename T>
class SplayTree {
	SPTNode<T> *root;

	void fixup(SPTNode<T> *pos);           // after finding or inserting
	SPTNode<T> *insert(const T& key, SPTNode<T> *father, SPTNode<T> *pos); // for recurssion
	void erase(SPTNode<T> *pos);
	void inorder(SPTNode<T> *cur, int *count);
	void levelorder();
public:
#ifdef SPT_DEBUG
	void print() const;
#endif
	SplayTree();
	virtual ~SplayTree();
	SPTNode<T> *getRoot() const;
	SPTNode<T> *find(const T& key);        // return root; const member func is naive!!!
	void insert(const T& key);
	void insert_recursion(const T& key);
	void erase(const T& key);
};

//-----------------------------------------------------------------------//
//SplayTreeNode(SPTNode) declaration

template <typename T>
SPTNode<T>::SPTNode():
	left(NULL),
	right(NULL),
	parent(NULL),
	depth(0),
	inorderIndex(0)
{

}

template <typename T>
SPTNode<T>::SPTNode(const T& key, SPTNode *parent):
	left(NULL),
	right(NULL),
	parent(parent),     // synchronize or custome
	key(key),           // |||
	depth(0),
	inorderIndex(0)
{
	if(parent) depth = parent->depth + 1;
}

template <typename T>
SPTNode<T>::~SPTNode()
{
	if(left) delete left;
	if(right) delete right; // recurssion delete for root!
}

template <typename T>
SPTNode<T> *SPTNode<T>::LL()
{
	SPTNode *temp = left;
	left = temp->right;
	if(temp->right) temp->right->parent = this;
	temp->right = this;
	parent = temp;

	return temp;
}

template <typename T>
SPTNode<T> *SPTNode<T>::RR()
{
	SPTNode *temp = right;
	right = temp->left;
	if(temp->left) temp->left->parent = this;
	temp->left = this;
	parent = temp;

	return temp;
}

template <typename T>
SPTNode<T> *SPTNode<T>::zig_zig(SPTNode *pos)
{
	SPTNode *ret = NULL;
	if(left && left->left == pos) {
		SPTNode *temp = LL();
		ret = temp->LL();
	} else if(right && right->right == pos) {
		SPTNode *temp = RR();
		ret = temp->RR();
	}
	return ret;
}

template <typename T>
SPTNode<T> *SPTNode<T>::zig_zag(SPTNode *pos)
{
	SPTNode *ret = NULL;
	if(left && left->right == pos) {
		SPTNode *temp = left->RR();
		temp->parent = this;
		left = temp;
		ret = LL();
	} else if (right && right->left == pos) {
		SPTNode *temp = right->LL();
		temp->parent = this;
		right = temp;
		ret = RR();
	}

	return ret;
}

template <typename T>
void SPTNode<T>::setOTHER()
{
	state = OTHER;
}

template <typename T>
void SPTNode<T>::setPATH()
{
	state = PATH;
}

template <typename T>
void SPTNode<T>::setRES()
{
	state = RES;
}


//--------------------------------------------------------------------------//
//SplayTree declaration

template <typename T>
SplayTree<T>::SplayTree():
	root(NULL)
{

}

template <typename T>
SplayTree<T>::~SplayTree()
{
	if(root) delete root;
}

template <typename T>
SPTNode<T> *SplayTree<T>::getRoot() const
{
	return root;
}

template <typename T>
void SplayTree<T>::inorder(SPTNode<T> *cur, int *count)
{
	if(cur != NULL) {
		inorder(cur->left, count);
		cur->inorderIndex = (*count)++;
		inorder(cur->right, count);
	}
}

template <typename T>
void SplayTree<T>::levelorder()
{
	queue<SPTNode<T> *> myQueue;
	if(root) {
		root->depth = 0;
		myQueue.push(root);
		while(!myQueue.empty()) {
			SPTNode<T> *cur = myQueue.front();
			myQueue.pop();
			cur->setOTHER();
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

template <typename T>
void SplayTree<T>::fixup(SPTNode<T> *pos)
{
	while(pos->parent) {
		if(pos->parent->parent) {
			SPTNode<T> *p = pos->parent, *g = p->parent;
			SPTNode<T> *temp = g->parent;
			int isLeft;
			if(temp) isLeft = temp->left == g;
			if(g->left == p && p->left == pos || 
			   g->right == p && p->right == pos) {
				pos = g->zig_zig(pos);
				pos->parent = temp; // NULL / non-NULL
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
				pos = pos->parent->LL();
				pos->parent = NULL;
			} else {
				pos = pos->parent->RR();
				pos->parent = NULL;
			}
		}
	}	
	root = pos;

	return;
}

template <typename T>
SPTNode<T> *SplayTree<T>::find(const T& key)
{
	SPTNode<T> *ret = NULL, *work = root;
	// reset to OTHER!
	levelorder(); 
	// reset to OTHER!
	while(work) {
		work->setPATH();
		if(work->key == key) {
			ret = work;
			break;
		} else if(work->key > key) {
			work = work->left;
		} else {
			work = work->right;
		}
	}
	// root->parent == NULL
	if(ret) {
		ret->setRES();
		fixup(ret);
	}
	return ret; // NULL / has been set root
}

template <typename T>
SPTNode<T> *SplayTree<T>::insert(const T& key, SPTNode<T> *father, SPTNode<T> *pos)
{
	SPTNode<T> *ret = pos;
	if(!ret) {
		ret = new SPTNode<T>(key, father);
	} else if(pos->key > key) {
		ret->left = insert(key, ret, ret->left);
	} else if(pos->key < key){
		ret->right = insert(key, ret, ret->right);
	}

	return ret;
}

template <typename T>
void SplayTree<T>::insert_recursion(const T& key)
{
	root = insert(key, NULL, root);
	find(key);

	int count = 0;
	inorder(root, &count);
	levelorder();
	return;
}

template <typename T>
void SplayTree<T>::insert(const T& key)
{
	SPTNode<T> *work = root, *last = NULL;
	int isLeft = -1;
	while(work) {
		last = work;
		if(work->key > key) {
			work = work->left;
			isLeft = 1;
		} else if(work->key < key) {
			work = work->right;
			isLeft = 0;
		}
	}
	if(!last) {
		root = new SPTNode<T>(key, NULL);
	} else if(isLeft){
		last->left = new SPTNode<T>(key, last);
		fixup(last->left);
	} else {
		last->right = new SPTNode<T>(key, last);
		fixup(last->right);
	}

	int count = 0;
	inorder(root, &count);
	levelorder();
}

template <typename T>
void SplayTree<T>::erase(SPTNode<T> *pos)
{
	assert(pos);
	if(pos->left && pos->right) {
		SPTNode<T> *temp = pos->left;
		while(temp->right) temp = temp->right;
		pos->key = temp->key;
		pos = temp;
	}
	SPTNode<T> *parent = pos->parent;
	int isLeft;
	if(parent) isLeft = parent->left == pos;
	if(pos->left) {
		if(!parent) {
			root = pos->left;
			if(root) root->parent = NULL;
		} else if(isLeft) {
			parent->left = pos->left;
			if(pos->left) pos->left->parent = parent;
		} else {
			parent->right = pos->left;
			if(pos->left) pos->left->parent = parent;
		}
	} else {
		if(!parent) {
			root = pos->right;
			if(root) root->parent = NULL;
		} else if(isLeft) {
			parent->left = pos->right;
			if(pos->right) pos->right->parent = parent;
		} else {
			parent->right = pos->right;
			if(pos->right) pos->right->parent = parent;
		}		
	}
	pos->left = pos->right = NULL;
	delete pos;
	return;
}

template <typename T>
void SplayTree<T>::erase(const T& key)
{
	SPTNode<T> *temp = find(key);
	if(temp) erase(temp);

	int count = 0;
	inorder(root, &count);
	levelorder();
	return;
}


#ifdef SPT_DEBUG
template <typename T>
void SplayTree<T>::print() const
{
	typedef SPTNode<T> *Entry;
	stack<Entry> myStack;
	Entry work = root;
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
		else cout << "NULL ";
		cout << "right: ";
		if(top->right) cout << top->right->key << endl;
		else cout << "NULL" << endl;
		work = top->right;
	}
	return;
}
#endif

#endif