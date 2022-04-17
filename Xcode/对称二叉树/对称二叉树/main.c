//
//  main.c
//  对称二叉树
//
//  Created by zhourenxi on 2022/4/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    
};

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right){
    
    if (left ==NULL && right == NULL) {
        return true;
    }
    if (left == NULL && right != NULL) {
        return false;
    }
    
    if (left != NULL && right == NULL) {
        return false;
    }//排除简单结构上面的不对称
    
    return left->val == right->val &&_isSymmetric(left->right, right->left) && _isSymmetric(left->left, right->right);
    
}

bool isSymmetric(struct TreeNode* root){
    if (root ->left == NULL && root->right == NULL) {
            return true;
        }
    return _isSymmetric(root->left, root->right);
}

