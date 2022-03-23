//
//  main.c
//  相交链表
//
//  Created by zhourenxi on 2022/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
 int val;
    struct ListNode *next;
 
 };
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (headB == NULL ||headA == NULL) {
        return NULL;
    }
    
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    
    while (pA != pB) {
        
        if (pA != NULL) {
            pA = pA ->next;
        }
        else{
            pA = headB;
        }
        
        if (pB != NULL) {
            pB = pB ->next;
        }
        else
            pB = headA;
    }
    
    return pA;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
