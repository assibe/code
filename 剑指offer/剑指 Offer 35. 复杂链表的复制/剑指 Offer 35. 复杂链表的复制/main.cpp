//
//  main.cpp
//  剑指 Offer 35. 复杂链表的复制
//
//  Created by 周仁玺 on 2023/3/23.
//


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
    typedef struct Node{
     
        int val;
        Node* next;
        Node* random;
    }Node;
    
    
public:
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        
        while (nullptr != cur) {
            
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }//创建新的链表的对应关系
        
        cur =   head;
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        
        return map[cur];
    }
};
