#ifndef BST_H_
#define BST_H_

#include <cassert>

template<typename T>
struct BSTNode {
	T key;
	BSTNode *left;
	BSTNode *right;

	BSTNode(const T& key);
	virtual ~BSTNode(); // auto-recursion freeTree! hahah ==!
};

template <typename T>
BSTNode<T>::BSTNode(const T& key):
	key(key),
	left(nullptr),
	right(nullptr)
{

}

// root-first recurrensive dtor!
template <typename T>
BSTNode<T>::~BSTNode()
{
	if(left) delete left;
	if(right) delete right;
}

template <typename T>
class BST {

	BSTNode<T> *root;
public:

	BST();
	virtual ~BST();
	void insert(const T& key);
	void erase(const T& key);
	BSTNode<T> *insert(BSTNode<T> *cur, const T& key);
	void erase(BSTNode<T> *pos);
};

template <typename T>
BST<T>::BST():
	root(nullptr)
{

}

template <typename T>
BST<T>::~BST()
{
	if(root) delete root;
}

template <typename T>
BSTNode<T> *BST<T>::insert(BSTNode<T> *cur, const T& key)
{
	BSTNode<T> *ret = cur;
	if(cur == nullptr) {
		BSTNode<T> *work = new BSTNode<T>(key);
		ret = work;
	} else if(cur->key < key) {
		ret->right = insert(ret->right, key);
	} else if(cur->key > key) {
		ret->left = insert(ret->left, key);
	}
	// 
	// == key -> insert failed!
	//

	return ret;
}

template <typename T>
void BST<T>::erase(BSTNode<T> *pos, BSTNode<T> *parent)
{
	//assert(root != nullptr && pos != nullptr);
	if(root != nullptr && pos != nullptr) {
		BSTNode<T> *eraseFinal = pos, *itsParent;
		if(pos->right != nullptr && pos->left != nullptr) {
			eraseFinal = pos->left;
			parent = pos;
			while(eraseFinal->right) {
				parent = eraseFinal; 
				eraseFinal = eraseFinal->right;
			}
		}
		if(eraseFinal->right != nullptr) {

		} else {

		}
	}
}

#endif