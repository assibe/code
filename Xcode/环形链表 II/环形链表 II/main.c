//
//  main.c
//  环形链表 II
//
//  Created by zhourenxi on 2022/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    
    if (head ->next == NULL && head) {
        return NULL;
    }
    
    struct ListNode *pA = head;
    struct ListNode *pB = head -> next;
    
    while (pA) {
        
        pB = head;
        for (; pB ->next != pA; pB = pB ->next) {
            if (pA ->next == pB) {
                return pB;
            }
        }
        pA = pA -> next;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
