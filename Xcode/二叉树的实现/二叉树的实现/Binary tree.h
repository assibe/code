//
//  Binary tree.h
//  二叉树的实现
//
//  Created by zhourenxi on 2022/4/16.
//

#ifndef Binary_tree_h
#define Binary_tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


#endif /* Binary_tree_h */

typedef int BTDataType;

struct BinaryTreeNode{
    
    BTDataType data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    
};

struct BinaryTreeNode *BuyBinary(BTDataType x);
//建立一个新的节点并且赋值

void PrevBinary(struct BinaryTreeNode  *root);

int BinarySize(struct BinaryTreeNode *root);//计算所以节点的数量

int BinaryTreeLeafSize(struct BinaryTreeNode *root);

int BinaryTreeKSize(struct BinaryTreeNode  *root,int k);

int BinaryTreeDepth(struct BinaryTreeNode *root);

void LeveLoder(struct BinaryTreeNode *root);

bool BinaryTreeComplete( struct BinaryTreeNode* root);

void BinaryTreeDestory(struct BinaryTreeNode* root);

struct BinaryTreeNode* CreateTree(struct BinaryTreeNode *root);






//typedef char BTDataType;
 
//typedef struct BinaryTreeNode
//{
//    BTDataType _data;
//    struct BinaryTreeNode* _left;
//    struct BinaryTreeNode* _right;
//}BTNode;
//
//
//// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//// 二叉树销毁
//void BinaryTreeDestory(BTNode** root);
//// 二叉树节点个数
//int BinaryTreeSize(BTNode* root);
//// 二叉树叶子节点个数
//int BinaryTreeLeafSize(BTNode* root);
//// 二叉树第k层节点个数
//int BinaryTreeLevelKSize(BTNode* root, int k);
//// 二叉树查找值为x的节点
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//// 二叉树前序遍历
//void BinaryTreePrevOrder(BTNode* root);
//// 二叉树中序遍历
//void BinaryTreeInOrder(BTNode* root);
//// 二叉树后序遍历
//void BinaryTreePostOrder(BTNode* root);
//// 层序遍历
//void BinaryTreeLevelOrder(BTNode* root);
//// 判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root);
