//
//  main.c
//  单值二叉树
//
//  Created by zhourenxi on 2022/4/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

bool _isUnivalTree(struct TreeNode *root,int val){
    
    if (root == NULL) {
        return true;
    }
    
    if (root->val != val) {
        return false;
    }
    
    return _isUnivalTree(root->left, val)&& _isUnivalTree(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
    
    if (root == NULL) {
        return true;
    }
    
    int val = root->val;
    return _isUnivalTree(root, val);
}
