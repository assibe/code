//
//  main.cpp
//  AVL树
//
//  Created by zhourenxi on 2022/9/19.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

using namespace std;

template <class K,class V>

struct  AVLTreeNode{
    
public:
    int _bf;
    
    pair<K, V> _kv;
    AVLTreeNode<K,V>* _left;
    AVLTreeNode<K,V>* _right;
    AVLTreeNode<K,V>* _parent;
    
    AVLTreeNode(const pair<V, K> &kv)
    :_kv(kv)
    ,_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr){}
   
    
};






 
// AVL: 二叉搜索树 + 平衡因子的限制
//template<class T>
//class AVLTree
//{
//    typedef AVLTreeNode<T> Node;
//public:
//    AVLTree()
//        : _pRoot(nullptr)
//    {}
//
//    // 在AVL树中插入值为data的节点
//    bool Insert(const T& data);
//
//    // AVL树的验证
//    bool IsAVLTree()
//    {
//        return _IsAVLTree(_pRoot);
//    }
//
//private:
//    // 根据AVL树的概念验证pRoot是否为有效的AVL树
//    bool _IsAVLTree(Node* pRoot);
//    size_t _Height(Node* pRoot);
//    // 右单旋
//    void RotateR(Node* pParent);
//    // 左单旋
//    void RotateL(Node* pParent);
//    // 右左双旋
//    void RotateRL(Node* pParent);
//    // 左右双旋
//    void RotateLR(Node* pParent);
//
//private:
//    Node* _pRoot;
//};
