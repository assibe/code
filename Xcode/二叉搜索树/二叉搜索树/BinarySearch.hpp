//
//  BinarySearch.hpp
//  二叉搜索树
//
//  Created by zhourenxi on 2022/9/11.
//

#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include <stdio.h>
#include <iostream>

#endif /* BinarySearch_hpp */

using namespace std;

template<class k>

struct BSTreeNode{
    
    BSTreeNode <k> *_left;
    BSTreeNode <k> *_right;
    
    k _key;
    
    BSTreeNode(const k& key)
    :_left(nullptr)
    ,_right(nullptr)
    ,_key(key)
    {};
    
};

template<class K>

class BSTree{
   
    typedef BSTreeNode<K> Node;
    
public:
    
    bool Insert(const K& key){
        
        if (_root == nullptr) {
            
            _root = new Node(key);
            return true;
        }
        
        Node* parent = nullptr;
        Node* cur = _root;
        
        while (cur) {
            
            if (cur-> _key < key) {
                
                parent = cur;
                cur = cur->_right;
                
            }
            else if (cur ->_key < key){
                
                parent = cur;
                cur = cur->left;
                
            }else{
                return  false;
            }
        }
        
        cur = new Node(key);
        if (cur->_key < key ) {
            
            parent->_right = cur;
            
        }
        else{
        
            parent->_left = cur;
            
        }
        
        return true;
    }
    
    bool Find(const K& key){
        
        Node* cur = _root;
        while (cur) {
            
            if (cur-> _key > key) {
                
                cur = cur->_right;
                
            }
            else if(cur-> _left < key){
                
                cur = cur->_left;
                
            }
            else{
                
                return true;
                
            }
            
        }
        
        return false;
    };
    
    bool Erase(const K& key){
        
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur) {
            
            if (cur-> _key > key) {
                
                cur = cur->_right;
                
            }
            else if(cur-> _left < key){
                
                cur = cur->_left;
                
            }
            else{//找到了内容，可以进行相关的操作！
                
                if (cur->_left == nullptr) {
                    //没有父亲
                    if (cur == _root) {
                        
                        _root = cur->_right;
                        
                    }
                    else{
                        
                        if (cur == parent->_left) {
                            
                            parent->_left = cur->_left;
                            
                        }
                        else{
                         
                            parent->_left = cur->_left;
                            
                        }
                        
                    }
                    delete cur;
                    
                }
                else if (cur->_right == nullptr){
                    
                    if (cur == _root) {
                        _root = cur->_left;
                    }
                    else{
                        
                        parent->_right = cur->_right;
                    }
                    delete cur;
                }
                else if(cur->_right == nullptr){
                    
                    if (_root->_right == nullptr) {
                        
                        if (cur == _root) {
                            
                            _root = cur->_left;
                            
                        }
                        else{
                            
                            parent->_right = cur->_right;
                        }
                        
                    }
                    
                    delete cur;
                }
                else{
                    
                    
                
                }
            }
            }
        return true;
    }
    
    void InOrder(const K& key){
        
        _InOreder(key);
    }
    
    
private:
    Node* _root = nullptr;

    void _InOreder(Node *root){
        
        if (root == nullptr) {
            return;
        }
        
        _InOreder(root->_left);
        cout << root -> _key << " ";
        _InOreder(root->_right);
        
    };
    
};



