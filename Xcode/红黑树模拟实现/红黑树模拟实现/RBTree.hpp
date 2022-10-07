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
             
            if (grandfater->_left == parent) {
                
                Node* uncle = grandfater->_right;//叔叔的具体信息
                if (uncle &&uncle->_col == RED) {
                    
                    parent->_col = BLACK;
                    grandfater->_col = RED;
                    
                    cur = grandfater;
                    parent = cur ->_parent;
                }
                else{
                    
                    if (cur == parent->_left) {// 右单旋
                      // g
                     //p
                    //c
                        RotateR(grandfater);
                        parent->_col = BLACK;
                        grandfater->_col = RED;
                        
                    }
                    else{//双旋
                        //   g
                        //p
                        //  c
                        RotateL(parent);
                        RotateR(grandfater);
                        cur->_col = BLACK;
                        grandfater->_col = RED;
                        
                    }
                    break;
                }
                
            }
            else{
                
                Node* uncle = grandfater->_left;
                if (uncle && uncle->_col == RED) {
                    
                    parent->_col = BLACK;
                    grandfater->_col =  RED;
                    
                    cur = grandfater;
                    parent = grandfater->_parent;
                }
                else{
                  
                    if (cur == parent->_right) {
                        
                        RotateL(grandfater);
                        parent->_col = BLACK;
                        grandfater->_col = RED;
                        
                    }
                    else{
                        
                        RotateR(parent);
                        RotateL(grandfater);
                        cur->_col = BLACK;
                        grandfater->_col = RED;
                        
                    }
                    break;
                }
            }
        }
        
        _root->_col = BLACK;
        return true;
    }
    
    int _Heiht(Node* root){
        
        if (root == nullptr) {
            return 0;
        }
        
        int lh = _Heiht(root->_left);
        int rh = _Heiht(root->_right);
        
        return lh > rh ? lh + 1: rh + 1;
    }
    
    
private:

    
    void RotateL(Node* parent){
        
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        
        parent->_right = subRL;
        
        if (subRL) {
            subRL->_parent = parent;
        }
        
        Node* ppNode = parent->_parent;
        
        subR->_left = parent;
        parent->_parent = subR;
        
        if (parent == _root) {
            _root->_parent = nullptr;
            _root = subR;
        }
        else{
            
            if (ppNode->_left == parent) {
                ppNode->_left = subR;
            }
            else{
                ppNode->_right = subR;
            }
        }
        
    }
    
    void RotateR(Node* parent){
        
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        
        parent->_right = subLR;
        if (subLR) {//判读断是非为空
            subLR ->_parent =parent;
        }
        
        Node* pNode = parent->_parent;
        subL = parent;
        parent->_parent = subL;
        
        if (parent == _root) {
            _root = subL;
            _root->_parent = nullptr;
        }
        else{
            subL->_parent = pNode;
            if (pNode->_left == parent) {
                pNode->_left = subL;
            }
            else{
                pNode->_right = subL;
            }
            
        }
        
    }
    
    
private:
    Node* _root = nullptr;
    
};



