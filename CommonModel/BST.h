#ifndef BST_H_
#define BST_H_

#include <cassert>
#include <stack>
#include <queue>
#include "Common.h"

using namespace std;

#define BST_DEBUG

template<typename T>
struct BSTNode {
	T key;
	BSTNode *left;
	BSTNode *right;

	int height;
	int depth;
	int inorderIndex;
	NodeType state;

	BSTNode(const T& key);
	virtual ~BSTNode(); // auto-recursion freeTree! hahah ==!
};

template <typename T>
BSTNode<T>::BSTNode(const T& key):
	key(key),
	left(nullptr),
	right(nullptr),
	height(0),
	depth(0),
	inorderIndex(0),
	state(OTHER)
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
	BSTNode<T> *insert(BSTNode<T> *cur, const T& key);
	void erase(BSTNode<T> *pos, BSTNode<T> *parent);
	void erase(BSTNode<T> *pos);
	int getHeight(BSTNode<T> *pos);
	void inorder(BSTNode<T> *cur, int *count);
	void levelorder();
public:
#ifdef BST_DEBUG
	void print(BSTNode<T> *cur);
	void print();
#endif

	BST();
	virtual ~BST();
	BSTNode<T> *getRoot() const;
	void insert(const T& key);
	BSTNode<T> *find(const T& key);
	void erase(const T& key);
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

template<typename T>
int BST<T>::getHeight(BSTNode<T> *pos)
{
	if(!pos) {
		return -1;
	} else {
		int lHeight = getHeight(pos->left);
		int rHeight = getHeight(pos->right);
		pos->height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
		return pos->height;
	}
}


template <typename T>
void BST<T>::inorder(BSTNode<T> *cur, int *current)
{
	if(cur) {
		inorder(cur->left, current);
		cur->inorderIndex = (*current)++;
		inorder(cur->right, current);
	}
}

template <typename T>
void BST<T>::levelorder()
{
	queue<BSTNode<T> *> myQueue;
	if(root) {
		root->depth = 0;
		myQueue.push(root);
		while(!myQueue.empty()) {
			BSTNode<T> *cur = myQueue.front();
			cur->state = OTHER;
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

template <typename T>
BSTNode<T> *BST<T>::getRoot() const
{
	return root;
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
	} else {
		ret->left = insert(ret->left, key);
	}
	// 
	// == key -> insert failed!
	//
	ret->height = getHeight(ret);
	return ret;
}

template <typename T>
void BST<T>::insert(const T& key)
{
	root = insert(root, key);
	int count = 0;
	inorder(root, &count);
	levelorder();
}

template <typename T>
void BST<T>::erase(BSTNode<T> *pos, BSTNode<T> *parent)
{
	//assert(root != nullptr && pos != nullptr);
	if(root != nullptr && pos != nullptr) {
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
				root = eraseFinal->right; // erase a root(sea node)
			} else {
				bool isLeft = parent->left == eraseFinal;
				if(isLeft) parent->left = eraseFinal->right;
				else parent->right = eraseFinal->right;
			}
		} else {
			if(parent == nullptr) {
				root = eraseFinal->left; // erase a root(sea node)
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

template <typename T>
void BST<T>::erase(BSTNode<T> *pos)
{
	stack<BSTNode<T> *> myStack;
	BSTNode<T> *work = root;
	while(work->key != pos->key) {
		myStack.push(work);
		if(work->key > pos->key) {
			work = work->left;
		} else {
			work = work->right;
		}
	} // pos is not inStack()
	BSTNode<T> *delPos = pos;
	if(pos->right && pos->left) {
		myStack.push(pos);
		delPos = pos->left;
		while(delPos->right) {
			myStack.push(delPos);
			delPos = delPos->right;
		}
		pos->key = delPos->key;
	}
	BSTNode<T> *after = delPos->right ? delPos->right : delPos->left, *level;
	if(delPos == root) {
		root = after; // maybe nullptr;
	} else {
		// at least one BSTNode in stack
		BSTNode<T> *temp = myStack.top();
		myStack.pop();

		level = temp; // at least oldRoot!!!
		if(temp->left == delPos) {
			temp->left = after;
		} else {
			temp->right = after;
		}
		level->height = getHeight(level);
		delPos->left = delPos->right = nullptr;
		delete delPos;

		// level stands for top/current !
		// temp last top !
		
		while(!myStack.empty()) {
			BSTNode<T> *top = myStack.top();
			myStack.pop();
			if(top->left == temp) {
				top->left = level;
				level = top;
			} else {
				top->right = level;
				level = top;
			}
			temp = top;
			level->height = getHeight(level);
		}
		root = level;
	}
	return;
}

template <typename T>
BSTNode<T> *BST<T>::find(const T& key)
{
	BSTNode<T> *ret = nullptr, *work = root;
	// reset to OTHER!
	levelorder(); 
	// reset to OTHER!
	while(work) {
		work->state = PATH;
		if(work->key == key) {
			ret = work;
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

template <typename T>
void BST<T>::erase(const T& key)
{
	BSTNode<T> *work = find(key);
	if(work != nullptr) erase(work);
	int count = 0;
	inorder(root, &count);
	levelorder();
}


// just for debug

#ifdef BST_DEBUG
template <typename T>
void BST<T>::print(BSTNode<T> *cur)
{
	if(cur) {
		print(cur->left);
		cout << "Key = " << cur->key << ", Height = " << cur->height << endl;
		cout << "Depth = " << cur->depth << ", inorderIndex = " << cur->inorderIndex << endl;
		cout << "left is " << (cur->left ? to_string(cur->left->key) : "nullptr") << endl;
		cout << "right is " << (cur->right ? to_string(cur->right->key) : "nullptr") << endl;
		print(cur->right);
	}
}

template <typename T>
void BST<T>::print()
{
	print(root);
	return;
}
#endif

#endif
