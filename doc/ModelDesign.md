# DSV Model Design
### 设计任务

设计极为基础的数据结构, 以查找树(有序词典)为主要实现模型;
设计二叉查找树, 平衡二叉树, 伸展树, 左式堆, 哈夫曼树(贪心构造算法), 红黑树;

- **设计模型基类, 方便ViewModel层进行暴露**

   - 抽象各种模型共用的属性与方法, 设计必要的虚函数与纯虚函数
   - 设计基类(模板)树节点, 设计基类(模板)树

- **设计模型二叉查找树(Binary Search Tree)**

   - 支持操作: 插入, 删除, 查找, 清空
   - 结构: 二叉树, 树的度为2
   - 性质: 左右满足全序关系

- **设计模型平衡二叉树(AVL Tree)**

   - 支持操作: 插入, 删除, 查找, 清空
   - 结构: 二叉树, 树的度为2
   - 性质: 二叉查找树, 平衡因子(Balance Factor)  \in  {-1, 0, 1}
   
- **设计模型伸展树(Splay Tree)**
  
   - 支持操作: 插入, 删除, 查找, 清空
   - 结构: 二叉树, 树的度为2
   - 性质: 二叉查找树, 插入, 查找后的key 通过单旋转或双旋转至根节点
   
- **设计模型左式堆(Leftist Heap)**
  
   - 支持操作: 插入, 删除最大(最小), 清空
   - 结构: 二叉树
   - 性质: 堆序(偏序关系), NPL(左子树) >= NPL(右子树)
   
- **设计模型哈夫曼树(Huffman Tree)(使用Huffman 构造算法)**
  
   - 支持操作: 插入, 删除后通过Huffman贪心算法重新构建, 清空
   - 结构: 二叉树
   - 性质: 本质是左0右1的字典树
   
- **设计模型红黑树(RB-Tree)**

   - 支持操作: 插入, 删除, 查找, 清空
   - 结构: 二叉树
   - 性质: 
      1. 每一个节点是红红色或黑色
      2. 根节点是黑色的
      3. 叶子节点NIL是黑色的
      4. 有树边相连的2个节点不同时为红色
      5. 从任意节点出发, 黑高度与路径无关

---
### 设计思路与方案

- **模型基类设计方案**
  
   - 提供共有的基本成员函数, 如中序, 层序遍历等
   - 提供共有的成员对象`left`, `right`, `key`, `depth`
   - 继承属性通知发生器(`Proxy_PropertyNotification<T>`)
   - 继承命令通知发生器(`Proxy_CommandNotification<T>`)
   - 设计`virtual`析构函数, `virtual`清空函数(不同模型将使用不同清空动作)
   
- **二叉查找树设计方案**

   - 树节点继承基类树节点, 树继承基类树
   - 实现插入, 删除, 查找算法
   - 节点不需要增加其他属性
   - 树不需要增加其他属性 

- **平衡二叉树设计方案**
  
   - 树节点继承基类树节点, 树继承基类树
   - 实现插入, 删除, 查找算法, `RR`, `LL`,  `LR`, `RL`算法
   - 节点增加属性`height`信息, `parent`信息
   - 树不需要增加其他属型性
   
- **伸展树设计方案**
  
   - 树节点继承基类树节点, 树继承基类树
   - 实现插入, 删除, 查找算法, `RR`, `LL`,  `LR`, `RL`算法, 删除调整, 插入调整算法
   - 节点增加属性 `parent`信息
   - 树不需要增加其他属性 
   
- **左式堆设计方案**

   - 树节点继承基类树节点, 树继承基类树
   - 实现`Merge`算法, 在此基础上实现插入, 删除算法
   - 节点增加属性`NPL(Null Path Length)`信息
   - 树不需要增加其他属性

- **哈夫曼树设计方案**

   - 树节点继承基类树节点, 树继承基类树
   - 实现`Huffman`贪心构造算法

- **红黑树设计方案**

   - 树节点继承基类树节点, 树继承基类树
   - 实现插入, 删除, 查找算法, `RR`, `LL`,  `LR`, `RL`算法, 删除调整, 插入调整算法
   - 删除分为左右对称共8个`case`, 插入分为左右对称共6个`case`
   - 节点增加属性`NPL(Null Path Length)`信息, Red, Black信息
   - 树增加属性`NIL`节点的信息

---
### 设计实现

- **模型基类实现**

   - 模型基类树节点模板声明
   ```C++
   template <typename T>
   struct BaseNode {
        T key;
        BaseNode *left;
        BaseNode *right;
   
        int depth;
        int inorderIndex; 
        NodeType state;
        NodeColor color;
   
        BaseNode(const T& key);
        virtual ~BaseNode(); 
    };
   ```
   - 模型基类树模板声明
   ```C++
   template <typename T, typename S = std::less<T>>
   class BaseTree : public Proxy_PropertyNotification<BaseTree<T, S>>, 
				 public Proxy_CommandNotification<BaseTree<T, S>> {
   protected:
        BaseNode<T> *root;
   protected:
        void inorder(BaseNode<T> *cur, int *count);
        void levelorder();
   public:
        BaseTree();
        virtual ~BaseTree();
        BaseNode<T> *getRoot();
        virtual BaseNode<T> *getNIL();
        void clear();
   };
   ```

- **二叉查找树实现**

   - 二叉查找树 . 树节点模板声明
   ```C++
   template<typename T>
   struct BSTNode : public BaseNode<T>{
		BSTNode(const T& key);
		virtual ~BSTNode(); // auto-recursion freeTree! hahah ==!
   };
   ```
   - 二叉查找树 . 树模板声明
   ```C++
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
   ```

- **平衡二叉树实现**

   - 平衡二叉树 . 树节点模板声明
   ```C++
   template<typename T>
   struct AVLNode : public BaseNode<T>{
		int height;

		AVLNode(const T& key);
		~AVLNode(); // auto-recursion freeTree! hahah ==!
   };
   ```
   - 平衡二叉树 . 树模板声明
   ```C++
   template<typename T, typename S = less<T>>
   class AVLTree : public BaseTree<T, S> {	
		// root is a BaseNode 
		// pointer is a member of BaseTree
		int getHeight(BaseNode<T> *_pos);
		BaseNode<T> *RR(BaseNode<T> *pos);
		BaseNode<T> *LL(BaseNode<T> *pos);
		BaseNode<T> *RL(BaseNode<T> *pos);
		BaseNode<T> *LR(BaseNode<T> *pos);
		void erase(BaseNode<T> *pos);
		BaseNode<T> *insert(BaseNode<T> *pos, const T& key); //recurson for implementation
   public:
   #ifdef AVL_DEBUG
		void print(BaseNode<T> *cur);
		void print();
   #endif
		AVLTree();
		virtual ~AVLTree();
		void insert(const T& key);	
		void erase(const T& key);
		AVLNode<T> *find(const T& key);
   };
   ```

- **伸展树实现**

   - 伸展树 . 树节点模板声明
   ```C++
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
   ```
   - 伸展树 . 树模板声明
   ```C++
   template <typename T, typename S = less<T>>
   class SplayTree : public BaseTree<T, S>{
		void fixup(SPTNode<T> *pos);     // after finding or inserting
		BaseNode<T> *
		insert(const T& key, BaseNode<T> *father, BaseNode<T> *pos); // for recurssion
		void erase(BaseNode<T> *pos);
   public:
   #ifdef SPT_DEBUG
		void print() const;
   #endif
		SplayTree();
		virtual ~SplayTree();
		SPTNode<T> *find(const T& key); // return this->root; const member func is naive!!!
		void insert(const T& key);
		void insert_recursion(const T& key);
		void erase(const T& key);
   };
   ```
- **左式堆实现**

   - 左式堆 . 树节点模板声明
   ```C++
   template <typename T>
   struct LeftistNode : public BaseNode<T> {
		int NPL;
		LeftistNode(const T& key);
		virtual ~LeftistNode();
   };
   ```
   - 左式堆 . 树模板声明
   ```C++
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
   ```
- **哈夫曼树实现**

   - 哈夫曼树 . 树节点模板声明
   ```C++
   template<typename T>
   struct HFNode : public BaseNode<T>
   {
    	HFNode(const T& value);
    	virtual ~HFNode();
   };
   ```
   - 哈夫曼树 . 树模板声明
   ```C++
   template<typename T, typename S = less<T> >
   class HFTree : public BaseTree<T, S>{
   private:
    	std::vector<T> content;
    	void create();

   public:
    	HFTree();
    	virtual ~HFTree();

    	void insert(const T& value);
    	void erase(const T& value);
    	void clear();
    	HFNode<T> *find(const T& value);
   };
   ```
- **红黑树实现**
   - 红黑树 . 树节点模板声明
   ```C++
   template <typename T>
   struct RBTNode : public BaseNode<T> {
		BaseNode<T> *parent;
		RBTNode(const T& key);
		virtual ~RBTNode();
   };
   ```
   - 红黑树 . 树模板声明
   ```C++
   
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
		virtual BaseNode<T> *getNIL() override;
   };
   ```

---
### 单元测试
- 查找树单元测试
   - 二叉查找树
   ```C++
   #include "BST.h"
   int main()
   {
			BST<int> *bst = new BST<int>;
			bst->insert(5);
			bst->insert(3);
			bst->insert(4);
			bst->insert(6);
			bst->insert(2);
			bst->insert(1);
			bst->insert(7);
			bst->insert(8);
			bst->insert(9);
			bst->insert(10);
			bst->insert(11);
	
			bst->erase(5);
			bst->erase(4);
			bst->erase(3);

			bst->print();

			delete bst;
			return 0;
   }
   ```
   - 平衡二叉树
   ```C++
   #include "AVLTree.h"

   int main()
   {
		AVLTree<int> *atree = new AVLTree<int>;
	
        atree->insert(1);
        atree->insert(2);
        atree->insert(3);
        atree->insert(4);
        atree->insert(5);
        atree->insert(6);
        atree->insert(7);
        atree->insert(8);
        atree->erase(8);
        atree->erase(5);
        atree->erase(7);
        atree->erase(6);
        atree->print();
        delete atree;
        return 0;
   }
   ```
   - 伸展树
   ```C++
   #include "SplayTree.h"
   #include <iostream>
   
   using namespace std;
   
   int main()
   {
        SplayTree<int> *myTree = new SplayTree<int>();
        myTree->insert(1);
        myTree->insert(2);
        myTree->insert(3);
        myTree->insert(4);
        myTree->insert(5);
        myTree->insert(6);
        myTree->find(1);	
        myTree->find(2);	
        myTree->find(3);	
        myTree->find(5);	

        myTree->erase(5);
        cout << "--------------------------------" << endl;
        myTree->print();	
        myTree->erase(4);
        cout << "--------------------------------" << endl;
        myTree->print();	
        myTree->erase(3);
        cout << "--------------------------------" << endl;
        myTree->print();
        myTree->erase(2);
        cout << "--------------------------------" << endl;
        myTree->print();
        myTree->erase(1);
        cout << "--------------------------------" << endl;
        myTree->print();
        myTree->erase(6);
        cout << "--------------------------------" << endl;
        myTree->print();
        delete myTree;
        return 0;
   }
   ```
   - 左式堆
   ```C++
   #include "LeftistHeap.h"
   #include <iostream>

   int main()
   {
        LeftistHeap<int> *lh = new LeftistHeap<int>;
        lh->insert(0);
        lh->insert(2);
        lh->insert(4);
        lh->insert(1);
        lh->insert(3);
        lh->insert(9);
        lh->insert(8);
        lh->insert(6);

        std::cout << "------------------------------------" << std::endl;
        lh->print();
        lh->erase();
        lh->erase();
        std::cout << "------------------------------------" << std::endl;
        lh->print();	

        delete lh;
        return 0;
   }
   ```
   - 哈夫曼树
   ```C++
   #include "HFTree.h"

   int main()
   {
        HFTree<int> *hfmt = new HFTree<int>;
        hfmt->insert(1);
        hfmt->insert(10);
        hfmt->insert(11);
        hfmt->insert(2);
        hfmt->insert(3);
        hfmt->insert(9);
        hfmt->insert(8);
        hfmt->insert(7);
        hfmt->insert(4);
        hfmt->insert(6);
        hfmt->insert(5);
        hfmt->find(1);
        hfmt->erase(1);
        delete hfmt;
        return 0;
   }
   ```
   - 红黑树
   ```C++
   #include "RBT.h"

   int main()
   {
        RBT<int> *rbt = new RBT<int>;
        rbt->insert(3);
        rbt->insert(4);
        rbt->insert(1);
        rbt->insert(2);
        rbt->insert(5);
        rbt->insert(10);
        rbt->insert(9);
        rbt->insert(7);
        rbt->insert(8);
        rbt->insert(6);

        rbt->erase(4);
        rbt->erase(1);
        rbt->erase(2);
        rbt->erase(3);

        rbt->print();
        delete rbt;
        return 0;
   }
   ```
   
---
### 图表说明
- UML类图

---
### 本课程心得体会
- 个人CPP工程技能收获
- 个人合作精神收获

---
