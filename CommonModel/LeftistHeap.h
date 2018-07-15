#include <iostream>
#include <queue>
#include <stack>
#include "Common.h"

using namespace std;

template <typename T>
struct LeftistNode {
	T key;
	LeftistNode *left;
	LeftistNode *right;
	int NPL;

	int depth;
	int inorderIndex;
	NodeType state;

	LeftistNode();
	virtual ~LeftistNode();
};

template <typename T>
class LeftistHeap {
	LeftistNode<T> *root;
	LeftistNode<T> *merge1(LeftistNode<T> *h1, LeftistNode<T> *h2);
	void merge2(LeftistNode<T> *h1, LeftistNode<T> *h2);
	LeftistNode<T> *insert(LeftistNode<T> *root, const T& key);
	LeftistNode<T> *erase(LeftistNode<T> *root);  // erase minimal internal!
public:
	LeftistHeap();
	virtual ~LeftistHeap();

	LeftistNode<T> *getRoot() const;  // also is heap-top
	void insert(const T& key);
	void erase(const T& key);         // erase minimal
};