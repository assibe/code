//
//  main.c
//  链表的中间结点
//
//  Created by zhourenxi on 2022/3/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head){//快慢指针
    
    struct ListNode *fast = head;
    struct ListNode *low = head;
    
    while (fast && fast -> next) {
        
        fast = fast -> next ->next;
        low = low->next->next;
    }
    return low;
}
