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

	RBTNode<T> *insert(RBTNode<T> *pivot, const T& key);
	RBTNode<T> *insertFixup(RBTNode<T> *pivot, RBTNode<T> *current);
	RBTNode<T> *find(RBTNode<T> *pivot, const T& key, RBTNode<T> *NIL);
	RBTNode<T> *erase(RBTNode<T> *pivot, RBTNode<T> *pos);
	RBTNode<T> *eraseFixup(RBTNode<T> *pivot, RBTNode<T> *x);
public:	
	RBT();
	virtual ~RBT();
	void insert(const T& key);
	RBTNode<T> *find(const T& key);
	void erase(const T& key);
};

template <typename T, typename S>
RBT<T, S>::RBT():
	BaseTree<T, S>()
{
	// to-do
	// RBT require a empty black root
	// int == 0 
	// bad/dirty design
	root = new RBTNode<T>(0);
	root->color = BLACK;
}

template <typename T, typename S>
RBT<T, S>::~RBT()
{
	// trival
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
RBTNode<T> *RBT<T, S>::RR(RBTNode<T> *NIL, RBTNode<T> *root)
{

}

////////////////////////////////////////////////////////////
// !!! ??? !!!
// NIL Node will be initilized while inserting first key
// !!! ??? !!!
////////////////////////////////////////////////////////////

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::insert(RBTNode<T> *root, const T& key)
{

}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::insertFixup(RBTNode<T> *root, RBTNode<T> *current)
{

}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::find(RBTNode<T> *root, const T& key, RBTNode<T> *NIL)
{

}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::erase(RBTNode<T> *root, RBTNode<T> *pos)
{

}

template <typename T, typename S>
RBTNode<T> *RBT<T, S>::eraseFixup(RBTNode<T> *root, RBTNode<T> *x)
{

}

#endif