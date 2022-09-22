//
//  main.cpp
//  二叉树的层序遍历 II
//
//  Created by zhourenxi on 2022/9/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//using std::queue;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
};

class Solution{
public:
    vector<vector<int>>levelOrederBottom(TreeNode* root){
     
        auto levelOreder = vector<vector<int>>();
        if (!root) {
            
            return levelOreder;
            
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            auto level = vector<int>();
            int size = (int)q.size();
            
            for (int i = 0; i < size; i++) {
                
                auto node = q.front();//储存下一个节点
                q.pop();
                level.push_back(node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
                
            }
            levelOreder.push_back(level);
            
            
        }
        reverse(levelOreder.begin(), levelOreder.end());
        
        return levelOreder;
    }
    
};

