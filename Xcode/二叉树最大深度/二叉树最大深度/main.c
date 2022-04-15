//
//  main.c
//  二叉树最大深度
//
//  Created by zhourenxi on 2022/4/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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


int maxDepth(struct TreeNode* root){
    
    if (root == NULL) {
        return 0;
    }
    size_t right = maxDepth(root->right) + 1;
    size_t left = maxDepth(root->left) + 1;
    //递归！
    
    if (right>left) {
        return (int)right;
    }
    return (int)left;
}
