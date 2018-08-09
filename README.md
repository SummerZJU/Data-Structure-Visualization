# CSummerZJU总体报告 

### 项目简介

本项目旨在实现对常见数据结构进行各种操作的可视化演示。

以下为本项目所实现的数据结构类型与操作。

* **数据结构**

  二叉搜索树、平衡二叉搜索树、伸展树、左式堆、红黑树、霍夫曼树

* **操作**

  插入结点、删除结点、寻找结点、清空树

------------

### 开发环境

本项目基于QT4.6.0，通过git进行版本控制，利用Appveyor进行持续集成。

----------------------

### 迭代说明

* **第一轮迭代**

  在MVVM架构下实现整体框架，实现二叉搜索树的插入、删除、查找功能。
  
  - 二叉树
![](/image/Demo/BSTInsert.png) <br/> <br/>
![](/image/Demo/BSTErase.png) <br/> <br/>
![](/image/Demo/BSTFind.png)

* **第二轮迭代**

  添加二叉平衡搜索树、伸展树，实现数据结构的清除功能，并对图形界面进行美化。

  - AVL树
![](/image/Demo/AVLTreeInsert.png)  <br/> <br/>
![](/image/Demo/AVLTreeErase.png)  <br/> <br/>
![](/image/Demo/AVLTreeFind.png)

  - 伸展树
![](/image/Demo/SplayTreeInsert.png) <br/> <br/>
![](/image/Demo/SplayTreeErase.png) <br/> <br/>
![](/image/Demo/SplayTreeFind.png)

* **第三轮迭代**

  添加左式堆、红黑树、霍夫曼树，实现操作有误的报错机制，并修改代码bug。
  
  - 报错机制
![](/image/Demo/Error0.png) <br/> <br/>
![](/image/Demo/Error1.png)

  - 左式堆
![](/image/Demo/LeftistheapInsert.png) <br/> <br/>
![](/image/Demo/LeftistHeapErase.png)

  - Huffman树
![](/image/Demo/HFTreeInsert.png)

  - 红黑树
![](/image/Demo/RBTInsert.png) <br/> <br/>
![](/image/Demo/RBTErase.png) <br/> <br/>
![](/image/Demo/RBTFind.png)