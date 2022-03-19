//
//  main.c
//  移除链表元素
//
//  Created by zhourenxi on 2022/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

struct ListNode {
    int val;
    struct ListNode *next;
    
};

struct ListNode* removeElements(struct ListNode* head, int val){
   
    assert(head);
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    
    while (cur) {
        if (cur -> val != val) {
            prev = cur;
            cur =cur -> next;
        }
        else{
            struct ListNode *next = cur ->next;
            
            if (prev == NULL) {//   为头指针的时候，情况进行讨论
                
                free(cur);
                head = next;
                cur = next;
            }
            else{//不为开头的时候
                
                free(cur);
                prev -> next = next;
                cur = next;
            }
    }
    
}
    return head;
}
