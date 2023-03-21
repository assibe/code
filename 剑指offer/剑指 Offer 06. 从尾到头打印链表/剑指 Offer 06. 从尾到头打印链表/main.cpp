//
//  main.cpp
//  剑指 Offer 06. 从尾到头打印链表
//
//  Created by 周仁玺 on 2023/3/21.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;



class Solution {
public:
    vector<int> reversePrint(ListNode* head) {//这道题使用递归的解决方法使用消耗最好
        
        std::stack<int> s;
        while (head) {
            s.push(head->val);
            head = head->next;
        }
        
        vector<int> re;
        while (s.empty()) {
            re.push_back(s.top());
            s.pop();
        }
        
        return re;
    }
};
