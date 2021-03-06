//
//  Binary tree.c
//  二叉树的实现
//
//  Created by zhourenxi on 2022/4/16.
//

#include "Binary tree.h"
#include "Queue.h"

struct BinaryTreeNode *BuyBinary(BTDataType x){
    
    struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    
    return newNode;
}

void PrevBinary(struct BinaryTreeNode  *root){//前遍历，更改位置可以改变printf的位置信息@！
    if (root == NULL) {
        printf("NULL");
        return;
    }
    
    printf("%d ",root->data);
    PrevBinary(root->left);
    PrevBinary(root->right);
    
}

int BinarySize(struct BinaryTreeNode* root){//利用后序遍历
    if (root == NULL) {
        return 0;
    }
    return BinarySize(root->left) + BinarySize(root->right) +1;
}

int BinaryTreeLeafSize(struct BinaryTreeNode *root){
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL&& root->right == NULL) {
        return 1;
    }
    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeKSize(struct BinaryTreeNode  *root,int k){
    assert(k >= 1);
    if (root == NULL) {
        return 0;
    }
    
    if (k == 1 ) {
        return 1;
    }
    return BinaryTreeKSize(root->left, k-1) + BinaryTreeKSize(root->right, k-1);
}

int BinaryTreeDepth(struct BinaryTreeNode *root){
    if (root == NULL) {
        return 0;
    }
    
    return BinaryTreeDepth(root->left) > BinaryTreeDepth(root->right) ? BinaryTreeDepth(root->left) +1:BinaryTreeDepth(root->right)+1;
}

void LeveLoder(struct BinaryTreeNode *root){//逐层遍历，利用队列的性质进行内容的书写！
    struct  Queue q;
    QueueInit(&q);
    
    if (root) {
        QueuePush(&q, root);
    }
    
    while (!QueuEmpty(&q)) {
        //出一个入其子节点！
        struct BinaryTreeNode *front = QueueFront(&q);
        QueuePop(&q);
        
        printf("%d",front->data);
        if (front->left) {
            QueuePush(&q, front->left);
        }
        
        if (front->right) {
            QueuePush(&q, front->right);
        }
        //入队列
    }
    
    printf("\n");
    QueueDestroy(&q);
}

bool BinaryTreeComplete( struct BinaryTreeNode* root){
    
    struct Queue q;
    QueueInit(&q);
    
    if (root) {
        QueuePush(&q, root);
    }
    
    while (!QueuEmpty(&q)) {
        struct BinaryTreeNode *front = QueueFront(&q);
        QueuePop(&q);
        
        if (front == NULL) {
            break;
        }
        
        QueuePush(&q, root->left);
        QueuePush(&q,root->right);
    }
    
    while (!QueuEmpty(&q)) {
        struct BinaryTreeNode *front = QueueFront(&q);
        
        QueuePop(&q);
        if (front) {
            return false;
        }
    }
    
    return true;
}


void BinaryTreeDestory(struct BinaryTreeNode* root){
    
    if (root) {
        BinaryTreeDestory(root->right);
        BinaryTreeDestory(root->right);
    }
    free(root);
    root = NULL;
}




//{
//    if (*root)
//    {
//        BinaryTreeDestory(&(*root)->_left);
//        BinaryTreeDestory(&(*root)->_right);
//        free(*root);
//        *root = NULL;
//    }
//}
