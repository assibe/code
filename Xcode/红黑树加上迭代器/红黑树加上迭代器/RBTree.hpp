//
//  RBTree.hpp
//  红黑树加上迭代器
//
//  Created by 周仁玺 on 2022/10/10.
//


//迭代器通过不同的遍历得出相应的结果进行++与--

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>
#include <iostream>

//#include <pair>

#endif /* RBTree_hpp */

using std::pair;

enum Colour
{
    RED,
    BLACK,
};

template<class T>
struct RBTreeNode
{
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;
    T _data; // 数据

    Colour _col;

    RBTreeNode(const T& data)
        :_data(data)
        , _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _col(RED)
    {}
};


template<class T,class Ref,class Ptr>

struct _RBTreeItrator{
    
    typedef RBTreeNode<T> Node;
    typedef _RBTreeItrator<T, Ref, Ptr> Self;
    Node* _node;
    
    _RBTreeItrator(Node* node)
    :_node(node){}
    
    Ref operator*(){
        
        return _node->_data;
    }
    
    Ptr operator->(){
        
        return &_node->_data;
    }
    
    Self& operator++(){
        
        if (_node->_right == nullptr) {
            
            Node* cur = _node;
            Node* parent = _node->_parent;
            while (parent && parent->_right == cur) {
                
                cur = cur->_parent;
                parent = parent->_right;
                
            }
            
            _node = parent;
        }
        else{
            
            Node* subLeft = _node->_right;
            while (subLeft->_left) {
                
                subLeft = subLeft->_left;
                
            }
            
            _node = subLeft;
        }
        return *this;
    }
    
    Self operator++(int){
        
        Self tmp(*this);
        ++(*this);
        return tmp;
    }
                                          
    Self& operator--(){
        
        if (_node->_left) {
            
            Node* cur = _node;
            Node* parent = _node->_parent;
            while (parent && cur == parent->_left) {
                
                cur = cur->_parent;
                parent = parent->_parent;
            }
            
            _node = parent;
        } else {
            
            Node* SubRight = _node->_left;
            while (SubRight->_right) {
                
                SubRight = SubRight->_right;
                
            }
            
            _node = SubRight;
        }
        return *this;
    }
    
    Self operator--(int){
        
        Self tmp(*this);
        --(*this);
        
        return tmp;
    }
    
    bool operator!= (const Self& s)const{
        
        return _node != s._node;
    }
    
    bool operator==(const Self& s)const{
        
        return _node == s._node;
    }
    
};


template<class K,class T,class KeyofT>
class RBTree{
    
    typedef RBTreeNode<T> Node;
    typedef _RBTreeItrator<T, T&, T*> iterator;
    typedef _RBTreeItrator<T, const T&, const T*> const_iterator;
    
public:
    
    iterator Begin(){
        
        Node* subLeft = _root;
        while (subLeft && subLeft->_left) {
            
            subLeft = subLeft->_left;
            
        }
        return iterator(subLeft);
        
    }
    
    iterator End(){
        
        return iterator(nullptr);
    }
    
    const_iterator Begin()const{
        
        Node* subLeft = _root;
        
        while (subLeft && subLeft->_left) {
            
            subLeft = subLeft->_left;
            
        }
        
        return const_iterator(subLeft);
    }
    
    const_iterator End()const{
        
        return const_iterator(nullptr);
    }
    
    pair<iterator, bool> Insert(const T& data)
        {
            // 1、搜索树的规则插入
            // 2、看是否违反平衡规则，如果违反就需要处理：旋转
            if (_root == nullptr)
            {
                _root = new Node(data);
                _root->_col = BLACK;
                return make_pair(iterator(_root), true);
            }

            KeyOfT kot;

            Node* parent = nullptr;
            Node* cur = _root;
            while (cur)
            {
                if (kot(cur->_data) < kot(data))
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (kot(cur->_data) > kot(data))
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    return make_pair(iterator(cur), true);
                }
            }

            cur = new Node(data);
            Node* newnode = cur;
            cur->_col = RED;
            if (kot(parent->_data) < kot(data))
            {
                parent->_right = cur;
            }
            else
            {
                parent->_left = cur;
            }

            cur->_parent = parent;

            // 存在连续红色节点
            while (parent && parent->_col == RED)
            {
                Node* grandfater = parent->_parent;
                assert(grandfater);

                if (grandfater->_left == parent)
                {
                    Node* uncle = grandfater->_right;
                    // 情况一：
                    if (uncle && uncle->_col == RED) // 叔叔存在且为红
                    {
                        // 变色
                        parent->_col = uncle->_col = BLACK;
                        grandfater->_col = RED;

                        // 继续往上处理
                        cur = grandfater;
                        parent = cur->_parent;
                    }
                    else // 叔叔不存在 或者 叔叔存在且为黑
                    {
                        if (cur == parent->_left) // 单旋
                        {
                            //     g
                            //   p
                            // c
                            RotateR(grandfater);
                            parent->_col = BLACK;
                            grandfater->_col = RED;
                        }
                        else // 双旋
                        {
                            //     g
                            //   p
                            //     c
                            RotateL(parent);
                            RotateR(grandfater);
                            cur->_col = BLACK;
                            grandfater->_col = RED;
                        }

                        break;
                    }
                }
                else //(grandfater->_right == parent)
                {
                    Node* uncle = grandfater->_left;
                    // 情况一：
                    if (uncle && uncle->_col == RED)
                    {
                        // 变色
                        parent->_col = uncle->_col = BLACK;
                        grandfater->_col = RED;

                        // 继续往上处理
                        cur = grandfater;
                        parent = cur->_parent;
                    }
                    else
                    {
                        if (cur == parent->_right)
                        {
                            // g
                            //   p
                            //     c
                            RotateL(grandfater);
                            parent->_col = BLACK;
                            grandfater->_col = RED;
                        }
                        else // 双旋
                        {
                            // g
                            //   p
                            // c
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

            return make_pair(iterator(newnode), true);
        }

        void RotateL(Node* parent)
        {
            Node* subR = parent->_right;
            Node* subRL = subR->_left;

            parent->_right = subRL;
            if (subRL)
                subRL->_parent = parent;

            Node* ppNode = parent->_parent;

            subR->_left = parent;
            parent->_parent = subR;

            if (parent == _root)
            {
                _root = subR;
                _root->_parent = nullptr;
            }
            else
            {
                if (parent == ppNode->_left)
                {
                    ppNode->_left = subR;
                }
                else
                {
                    ppNode->_right = subR;
                }

                subR->_parent = ppNode;
            }
        }

        void RotateR(Node* parent)
        {
            Node* subL = parent->_left;
            Node* subLR = subL->_right;

            parent->_left = subLR;
            if (subLR)
                subLR->_parent = parent;

            Node* ppNode = parent->_parent;

            subL->_right = parent;
            parent->_parent = subL;

            if (parent == _root)
            {
                _root = subL;
                _root->_parent = nullptr;
            }
            else
            {
                if (ppNode->_left == parent)
                {
                    ppNode->_left = subL;
                }
                else
                {
                    ppNode->_right = subL;
                }
                subL->_parent = ppNode;
            }
        }

        iterator Find(const K& key)
        {
            Node* cur = _root;
            KeyOfT kot;
            while (cur)
            {
                if (kot(cur->_data) < key)
                {
                    cur = cur->_right;
                }
                else if (kot(cur->_data) > key)
                {
                    cur = cur->_left;
                }
                else
                {
                    return iterator(cur);
                }
            }

            return End();
        }
    
    
    
private:
    Node* _root = NULL;
};
