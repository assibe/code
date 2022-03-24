//
//  main.c
//  链表的回文结构
//
//  Created by zhourenxi on 2022/3/24.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

bool chkPalindrome( ListNode* A) {//利用快慢指针解决
        // write code here
    if (A == NULL || A->next == NULL)
                return true;
    ListNode *low ,*fast;
    
    low = fast = A;
    
    while (fast&&fast ->next) {//为空的两个判断条件！
        low = low -> next;
        fast = fast -> next ->  next;
    }
    
    ListNode *cur = low;
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    
    while (cur) {
        nxt = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nxt;
    }
    
    while (A && prev) {
        if (A ->val != prev ->val) {
            return false;
        }
        else{
            A = A->next;
            prev = prev->next;
        }
        }
    return true;
    }
