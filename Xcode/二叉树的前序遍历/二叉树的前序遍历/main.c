//
//  main.c
//  二叉树的前序遍历
//
//  Created by zhourenxi on 2022/4/17.
//

#include <stdio.h>
#include <stdlib.h>

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
int* preorderTraversal(struct TreeNode* root, int* returnSize){//前序遍历
    
    int *a = (int*)malloc(sizeof(int));
    
    return a;
    
}
int* _preorderTraversal(struct TreeNode* root, int* returnSize,);
