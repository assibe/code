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
#include <queue>
#include <time.h>

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
    
    typedef AVLTreeNode<K, V>  Node;
public:
    
    bool inseert(const pair<K, V> &kv){
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
        
        while (parent) {
            
            if (cur == parent->_right) {
                parent->_bf++;
            }
            else{
                parent->_bf--;
                
            }
            
            if (parent->_bf == 0) {
                break;
            }
            else if (parent->_bf == 1|| parent->_bf == -1){
                
                cur = parent->_parent;
            }
            else if (parent->_bf == 2|| parent->_bf == -2){//数不平衡需要旋转
                
            }
            else{
               // 存在平衡因子，之前就不对
                assert(false);
            }
        }
        
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









