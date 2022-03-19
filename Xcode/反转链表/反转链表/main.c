//
//  main.c
//  反转链表
//
//  Created by zhourenxi on 2022/3/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *MakeListNode(int c){
    
    struct ListNode *cur = NULL;
    cur -> next = NULL;
    cur -> val = c;
    return cur;
}

void SListPushBack(struct ListNode **pphead,int x){
    
    assert(pphead);
    if (*pphead == NULL) {
        *pphead = MakeListNode(x);
    }
    
    else if ((*pphead) -> next == NULL){
        *pphead = MakeListNode(x);
    }
    
    else{
        
        while ((*pphead) -> next != NULL)  {
            *pphead = (*pphead) -> next;
        }
        (*pphead)->next = MakeListNode(x);
        
    }
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode  * newHead = NULL;
    struct ListNode *cur = head;
    while (cur) {
        
        struct ListNode *next = cur -> next;
        cur->next =newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


