//
//  main.c
//  链表分割
//
//  Created by zhourenxi on 2022/3/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
    
    int val;
    struct ListNode *next;
    
}ListNode;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

//ListNode* partition(ListNode* pHead, int x) {
//         write code here
//
//
//    assert(pHead);  极端情况未考虑到
//    ListNode *cur1 = pHead;
//
//    while (cur1->next->val < x) {
//
//        cur1 = cur1->next;
//
//    }
//
//    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
//    newNode = cur1;
//
//    ListNode* cur2 = pHead;
//    while (cur2->next != cur1) {
//
//        cur2 = cur2 ->next;
//
//    }
//
//    cur2 ->next = NULL;
//    newNode -> next = pHead;
//    cur2 -> next = cur1;
//
//    return newNode;
//
//}

    ListNode* partition(ListNode* pHead, int x) {
        
        ListNode* newnode1head =  (ListNode*)malloc(sizeof(ListNode));
        ListNode* newnode2head = (ListNode*)malloc(sizeof(ListNode));
        ListNode* newnode1tail =  (ListNode*)malloc(sizeof(ListNode));
        ListNode* newnode2tail = (ListNode*)malloc(sizeof(ListNode));
        newnode1head = newnode1tail;
        newnode2head = newnode2tail;
        ListNode* cur = pHead;
      
        while (cur) {
            
            if (cur -> val < x) {
                newnode1tail -> next = cur;
                newnode1tail = newnode1tail -> next;
            }
            else{
                newnode2tail -> next = cur;
                newnode2tail = newnode2tail->next;
            }
            cur = cur -> next;
        }
        
        newnode1tail -> next = newnode2head -> next;//第一个数据为空
        newnode2tail ->next = NULL;
        return newnode1head -> next;
    }
