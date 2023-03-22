//
//  main.cpp
//  剑指 Offer 24. 反转链表
//
//  Created by 周仁玺 on 2023/3/22.
//
#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        stack<int> stack1;
        ListNode*  Head1 = head;
        while (head) {
            
            stack1.push(head->val);
            head = head->next;
            
        }
        
        ListNode* Head2 = Head1;
               while (Head1) {
                   
                   Head1->val = stack1.top();
                   stack1.pop();
                   Head1 = Head1->next;
               }
               
               return Head2;
       
    }
};
