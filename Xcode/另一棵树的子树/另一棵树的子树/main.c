//
//  main.c
//  另一棵树的子树
//
//  Created by zhourenxi on 2022/4/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


bool isSameTree(struct TreeNode *q,struct TreeNode *p){
    if (q == NULL && p != NULL) {
        return false;
    }
    
    if (q == NULL && p == NULL) {
        return true;
    }
    if (q != NULL && p == NULL) {
        return false;
    }
    
    if (q->val == p ->val) {
        return isSameTree(q->right, p->right)&&isSameTree(q->left, p->left);
    }
    else
        return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    
    if (root == NULL) {
        return false;
    }
    
    if (isSameTree(root, subRoot)) {
        return true;
    }
    else{
        return isSameTree(root->left, t) && isSameTree(root->right, t);
    }
        
}
