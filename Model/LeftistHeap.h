#ifndef LEFTISTHEAP_H_
#define LEFTISTHEAP_H_

#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include "../Common/TreeBase.h"
#include "../Common/Exception/ModelException.h"

using namespace std;

#define LEFTISTHEAP_DEBUG

template <typename T>
struct LeftistNode : public BaseNode<T> {
	int NPL;
	LeftistNode(const T& key);
	virtual ~LeftistNode();
};

//--------------------------------------------------------------------------//
//LeftistNode declaration

template <typename T>
LeftistNode<T>::LeftistNode(const T& key):
	BaseNode<T>(key),
	NPL(0)
{
	// trival
}

template <typename T>
LeftistNode<T>::~LeftistNode()
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



//----------------------------------------------------------------------------//
// LeftistHeap declaration


template <typename T, typename S = less<T>>
class LeftistHeap : public BaseTree<T, S> {
	BaseNode<T> *merge1(BaseNode<T> *h1, BaseNode<T> *h2);
	void merge2(LeftistNode<T> *h1, LeftistNode<T> *h2);
	BaseNode<T> *insert(BaseNode<T> *origin, const T& key);
public:
#ifdef LEFTISTHEAP_DEBUG
	void print(LeftistNode<T> *cur);
	void print();
#endif	
	LeftistHeap();
	virtual ~LeftistHeap();
	void insert(const T& key);
	void erase();                     // erase minimal
};

template <typename T, typename S>
LeftistHeap<T, S>::LeftistHeap():
	BaseTree<T, S>()
{
	// trival
}

template <typename T, typename S>
LeftistHeap<T, S>::~LeftistHeap()
{
	// trival
}

template <typename T, typename S>
BaseNode<T> *LeftistHeap<T, S>::merge1(BaseNode<T> *h1, BaseNode<T> *h2)
{
	BaseNode<T> *ret = nullptr;
	if(h1 == nullptr) {
		ret = h2;
	} else if(h2 == nullptr) {
		ret = h1;
	} else {
		// default max-heap -> greater min-heap
		if(S()(h1->key, h2->key)) { 
			merge2(dynamic_cast<LeftistNode<T> *>(h2), dynamic_cast<LeftistNode<T> *>(h1));
			ret = h2;
		} else {
			merge2(dynamic_cast<LeftistNode<T> *>(h1), dynamic_cast<LeftistNode<T> *>(h2));
			ret = h1;
		}
	}

	return ret;
}

template <typename T, typename S>
void LeftistHeap<T, S>::merge2(LeftistNode<T> *h1, LeftistNode<T> *h2)
{
	if(h1->left == nullptr) {
		h1->left = h2;
	} else {
		h1->right = merge1(h1->right, h2);
		if(dynamic_cast<LeftistNode<T> *>(h1->right)->NPL > 
		   dynamic_cast<LeftistNode<T> *>(h1->left)->NPL) {
			BaseNode<T> *temp = h1->left;
			h1->left = h1->right;
			h1->right = temp;
		}
		h1->NPL = dynamic_cast<LeftistNode<T> *>(h1->right)->NPL + 1;  // h2->NPL no change!!!
	}
}

template <typename T, typename S>
BaseNode<T> *LeftistHeap<T, S>::insert(BaseNode<T> *origin, const T& key)
{
	BaseNode<T> *ret = origin;
	BaseNode<T> *temp = new LeftistNode<T>(key);
	ret = merge1(this->root, temp);

	return ret;
}

template <typename T, typename S>
void LeftistHeap<T, S>::insert(const T& key)
{
	this->root = insert(this->root, key);
	int count = 0;
	this->inorder(this->root, &count);
	this->levelorder();

	this->Fire_OnPropertyChanged("Property Changed After Insert");
	return;
}

template <typename T, typename S>
void LeftistHeap<T, S>::erase()
{
	// here is seem to LeftistHeap::find()
	if(this->root != nullptr) {
		BaseNode<T> *del = this->root;
		this->root = merge1(this->root->left, this->root->right);
		del->left = del->right = nullptr;
		delete del;
		int count = 0;
		this->inorder(this->root, &count);
		this->levelorder();
		this->Fire_OnPropertyChanged("Property Changed After Erase");
	} else {
		throw ModelException("LeftistHeap Erase Failed");
	}
}

#ifdef LEFTISTHEAP_DEBUG
template <typename T, typename S>
void LeftistHeap<T, S>::print(LeftistNode<T> *cur)
{
	if(cur) {
		print(dynamic_cast<LeftistNode<T> *>(cur->left));
		cout << "Key = " << cur->key << ", NPL = " << cur->NPL << endl;
		cout << "Depth = " << cur->depth << ", inorderIndex = " << cur->inorderIndex << endl;
		cout << "left is " << (cur->left ? to_string(cur->left->key) : "nullptr") << endl;
		cout << "right is " << (cur->right ? to_string(cur->right->key) : "nullptr") << endl;
		print(dynamic_cast<LeftistNode<T> *>(cur->right));
	}
}

template <typename T, typename S>
void LeftistHeap<T, S>::print() 
{
	print(dynamic_cast<LeftistNode<T> *>(this->root));
	return;
}
#endif

#endif