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
    
    struct ListNode *cur = head;
    
    while (head -> val == val) {//排除头指针
        
        head = head -> next;
        free(cur);
        cur = head;
        
        if (cur -> next == NULL) {//
            return head;
        }
    }
    
    struct ListNode *prev = head;
    cur = cur ->next;
    
    while (cur) {
        
        if (cur->val == val) {
          
            prev ->next = cur->next;
            free(cur);
            cur = NULL;
            
            if (prev -> next == NULL) {
                return head;
            }
            
            prev = prev -> next;
            cur = cur->next;
            
        }
        else{
            
            prev = prev ->next;
            cur = cur -> next;
            
        }
            
    }
    return head;
    
};
