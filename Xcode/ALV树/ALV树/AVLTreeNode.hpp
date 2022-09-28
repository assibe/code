//
//  AVLTreeNode.hpp
//  ALV树
//
//  Created by 周仁玺 on 2022/9/28.
//

#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp

#include <stdio.h>
#include <utility>

#endif /* AVLTreeNode_hpp */

using std::pair;

template<class K,class V>

struct AVLTreeNode{

    AVLTreeNode(const pair<K, V>& kv)
    :_kv(kv),_left(nullptr),_parent(nullptr),_right(nullptr),_bf(0){}
    
public:
    
    pair<K, V> _kv;
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;
    int _bf;
    
    
};

template<class K,class V>

class AVLTree{
    
    typedef AVLTreeNode<K, V> Node;
public:
    
};









