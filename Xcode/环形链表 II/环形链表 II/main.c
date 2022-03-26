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
    
    assert(head);
    struct ListNode *low = head;
    struct ListNode *fast = head;
    
    while (fast) {
        
        if (fast->next == NULL) {
            return NULL;
        }
        
        low = low -> next;
        fast = fast -> next -> next;
        
        if (fast == low) {
            
            struct ListNode *ptr = head;
            while (ptr != low) {
                low = low -> next;
                ptr = ptr -> next;
            }
            return ptr;
        }
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
