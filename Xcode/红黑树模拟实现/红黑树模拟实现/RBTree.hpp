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
#include <assert.h>


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
    
    bool insert(const pair<K, V> &kv){
        
        if (_root == nullptr) {
            _root = new Node(kv);
            _root->_bf = 0;
            return true;
        }
        
        Node* parent = nullptr;
        Node* cur = _root;
        
        while (cur) {
            
            if (_root->_kv.first <= kv.first) {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first){
                
                parent = cur;
                cur = cur ->_left;
                
            }
            else{
                return false;
            }
        }
        
        cur = new Node(kv);
        if (parent->_kv.first > kv.first) {
            parent->_right = cur;
        }
        else{
            parent->_left = cur;
        }
        cur->_parent = parent;
        //按照搜索树的规则进行插入内容
        
        while (parent && parent->_col == RED) {//
            
            Node* grandfater = parent->_parent;
            assert(grandfater);
             
            
            
        }
        
        
        
    }
    
    
private:
    Node* _root = nullptr;
    
};



