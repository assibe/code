//
//  main.cpp
//  二叉树的层序遍历
//
//  Created by zhourenxi on 2022/9/18.
//

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//using namespace std;


class Solution {//通过把遍历完事东西放在一个堆之中
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ret;
        
        if (root == nullptr) {
            return  ret;
        }//先判断是否为空表
        
        queue<TreeNode*> q;
        q.push(root);//导入头节点到队列之中
        
        while (!q.empty()) {
            //一次遍历所以层的内容
            
            vector<int> level;
            int levelSize =(int) q.size();
            
            for (size_t i = 0; i < levelSize; i ++) {
                
                TreeNode* pCur = q.front();
                level.push_back(pCur->val);
                
                if (pCur->left) {
                    q.push(pCur->left);
                }
                
                if (pCur->right) {
                    q.push(pCur->right);
                }
                q.pop();
                
            }
            ret.push_back(level);
            
        }
        
        return ret;
    }
};

//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        // 如果是空树直接返回
//        vector<vector<int>> ret;
//        if(nullptr == root)
//            return ret;
//
//        queue<TreeNode*> q;
//        q.push(root);   // 已经将第一层节点放到队列中
//
//        while(!q.empty())
//        {
//            // 一次性将一层的所有节点全部遍历完
//            vector<int> level;
//            int levelSize = q.size();
//
//        // 该for将本层节点变量完成后，已经将下一层节点保存到队列中
//            for(size_t i = 0; i < levelSize; ++i)
//            {
//                TreeNode* pCur = q.front();
//                level.push_back(pCur->val);
//
//                // 如果该节点有左右子树，分别将左右子树入队列
//                if(pCur->left)
//                    q.push(pCur->left);
//
//                if(pCur->right)
//                    q.push(pCur->right);
//
//                q.pop();
//            }
//
//            ret.push_back(level);
//        }
//
//        return ret;
//    }
//};
//
//
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//
//struct SingeNode{
//
//    size_t data;
//    struct SingeNode *next;
//};
//
//void purge(SingeNode* Node){
//
//    struct SingeNode* p = Node->next;
//    while (p->next != nullptr) {
//
//        if (p->data == p->next->data) {
//            struct SingeNode *q;
//            q = p->next;
//            p->next = q->next;
//            delete q;
//
//        }
//        else{
//
//            p = p ->next;
//
//        }
//
//    }
//}
//
//
