//
//  main.cpp
//  105. 从前序与中序遍历序列构造二叉树
//
//  Created by 周仁玺 on 2022/9/27.
//

#include <iostream>
#include <vector>
#include <stack>


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

using namespace std;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (!preorder.size()) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inoredIndex = 0;
        
        for (int i = 1; i < preorder.size(); ++i) {
            
            int preorederVal = preorder[i];
            TreeNode* node = stk.top();
            
            if (node-> val != inorder[inoredIndex]) {
                
                node->left = new TreeNode(preorederVal);
                stk.push(node->left);
                
            }
            else{
                
                while (!stk.empty() && stk.top()->val == inorder[inoredIndex] ) {
                    
                    node = stk.top();
                    stk.pop();
                    inoredIndex++;
                    
                }
                node->right = new TreeNode(preorederVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
