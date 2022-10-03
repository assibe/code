//
//  RBTree.hpp
//  红黑树模拟实现
//
//  Created by 周仁玺 on 2022/10/3.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>
#include<utility>


#endif /* RBTree_hpp */


enum Colour{
    BLACK,
    RED,
    
};

using namespace std;

template<class K,class V>

struct RBTreeNode{
    
    RBTreeNode<K, V>* _left;
    RBTreeNode<K, V>* _right;
    RBTreeNode<K, V>* _parent;
    
    pair<K, V> _kv;
    Colour _col;//颜色定义
    
    RBTreeNode(const pair<K, V>  &kv)
    :_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr)
    ,_col(RED){};
    
};

template<class K,class V>

struct RBTree{
    typedef RBTreeNode<K, V> Node;
public:
    
    
private:
    Node* _root = nullptr;
    
}

