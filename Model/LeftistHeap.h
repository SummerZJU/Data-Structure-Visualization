#ifndef LEFTISTHEAP_H_
#define LEFTISTHEAP_H_

#include <iostream>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

#define LEFTISTHEAP_DEBUG

template <typename T>
struct LeftistNode {
	T key;
	LeftistNode *left;
	LeftistNode *right;
	int NPL;

	int depth;
	int inorderIndex;

	LeftistNode(const T& key);
	virtual ~LeftistNode();
};

template <typename T, typename S = less<T>>
class LeftistHeap {
	LeftistNode<T> *root;
	LeftistNode<T> *merge1(LeftistNode<T> *h1, LeftistNode<T> *h2);
	void merge2(LeftistNode<T> *h1, LeftistNode<T> *h2);
	LeftistNode<T> *insert(LeftistNode<T> *root, const T& key);
	LeftistNode<T> *erase(LeftistNode<T> *root);  // erase minimal internal!
	void inorder(LeftistNode<T> *cur, int *count);
	void levelorder();
public:
#ifdef LEFTISTHEAP_DEBUG
	void print(LeftistNode<T> *cur);
	void print();
#endif	
	LeftistHeap();
	virtual ~LeftistHeap();

	LeftistNode<T> *getRoot() const;  // also is heap-top
	void insert(const T& key);
	void erase();                     // erase minimal
};

//--------------------------------------------------------------------------//
//LeftistNode declaration

template <typename T>
LeftistNode<T>::LeftistNode(const T& key):
	key(key),
	left(nullptr),
	right(nullptr),
	NPL(0),
	depth(0),
	inorderIndex(0)
{

}

template <typename T>
LeftistNode<T>::~LeftistNode()
{
	if(left != nullptr) delete left;
	if(right != nullptr) delete right;
}

//----------------------------------------------------------------------------//
// LeftistHeap declaration

template <typename T, typename S>
LeftistHeap<T, S>::LeftistHeap():
	root(nullptr)
{

}

template <typename T, typename S>
LeftistHeap<T, S>::~LeftistHeap()
{
	if(root != nullptr) delete root;
}


template <typename T, typename S>
LeftistNode<T> *LeftistHeap<T, S>::getRoot() const
{
	return root;
}

template <typename T, typename S>
void LeftistHeap<T, S>::inorder(LeftistNode<T> *cur, int *count)
{
	if(cur != nullptr) {
		inorder(cur->left, count);
		cur->inorderIndex = (*count)++;
		inorder(cur->right, count);
	}
}

template <typename T, typename S>
void LeftistHeap<T, S>::levelorder()
{
	queue<LeftistNode<T> *> myQueue;
	if(root) {
		root->depth = 0;
		myQueue.push(root);
		while(!myQueue.empty()) {
			LeftistNode<T> *cur = myQueue.front();
			myQueue.pop();
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
LeftistNode<T> *LeftistHeap<T, S>::merge1(LeftistNode<T> *h1, LeftistNode<T> *h2)
{
	LeftistNode<T> *ret = nullptr;
	if(h1 == nullptr) {
		ret = h2;
	} else if(h2 == nullptr) {
		ret = h1;
	} else {
		// default max-heap -> greater min-heap
		if(S()(h1->key, h2->key)) { 
			merge2(h2, h1);
			ret = h2;
		} else {
			merge2(h1, h2);
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
		if(h1->right->NPL > h1->left->NPL) {
			LeftistNode<T> *temp = h1->left;
			h1->left = h1->right;
			h1->right = temp;
		}
		h1->NPL = h1->right->NPL + 1;  // h2->NPL no change!!!
	}
}

template <typename T, typename S>
LeftistNode<T> *LeftistHeap<T, S>::insert(LeftistNode<T> *root, const T& key)
{
	LeftistNode<T> *ret = root;
	LeftistNode<T> *temp = new LeftistNode<T>(key);
	ret = merge1(root, temp);

	return ret;
}

template <typename T, typename S>
void LeftistHeap<T, S>::insert(const T& key)
{
	root = insert(root, key);
	int count = 0;
	inorder(root, &count);
	levelorder();
	return;
}

template <typename T, typename S>
void LeftistHeap<T, S>::erase()
{
	if(root != nullptr) {
		LeftistNode<T> *del = root;
		root = merge1(root->left, root->right);
		del->left = del->right = nullptr;
		delete del;
		int count = 0;
		inorder(root, &count);
		levelorder();
	}
}

#ifdef LEFTISTHEAP_DEBUG
template <typename T, typename S>
void LeftistHeap<T, S>::print(LeftistNode<T> *cur)
{
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
void LeftistHeap<T, S>::print() 
{
	print(root);
	return;
}
#endif

#endif