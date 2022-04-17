//
//  main.c
//  相同的树
//
//  Created by zhourenxi on 2022/4/17.
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    if (p == NULL && q == NULL) {
        return true;
    };
    
    if (p == NULL && q != NULL) {
        return false;
    }
    
    if (q == NULL && p != NULL) {
        return false;
    }
    
    if (q->val == p->val) {
        
        return isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
    else
        return false;;
}
