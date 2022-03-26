//
//  main.c
//  环形链表
//
//  Created by zhourenxi on 2022/3/26.
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

struct ListNode {
    
    int val;
    struct ListNode *next;
    
};
bool hasCycle(struct ListNode *head) {//一般关于环形链表基本使用快慢指针解决
    
    struct ListNode *low = head;
    struct ListNode *fast = head;
    
    while (fast) {
        low = low ->next;
        if (fast ->next == NULL) {
            return false;
        }
        
        fast = fast ->next ->next;
        if (low == fast ) {
            return true;
        }
    }
    return false;
}
