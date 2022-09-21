//
//  main.cpp
//  根据二叉树创建字符串
//
//  Created by zhourenxi on 2022/9/18.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}






class Solution {
public:
    string tree2str(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        if (root->left == nullptr && root->right == nullptr) {
            return to_string(root->val);
        }
        if (root->right == nullptr) {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};



