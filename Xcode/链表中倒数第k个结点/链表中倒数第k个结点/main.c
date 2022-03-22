//
//  main.c
//  链表中倒数第k个结点
//
//  Created by zhourenxi on 2022/3/20.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

//题思路：
//快慢指针法 fast, slow, 首先让fast先走k步，然后fast,slow同时走，fast走到末尾时，slow走到倒数第k个节点。
//*/

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    
    struct ListNode *fast = pListHead;
    struct ListNode *low = pListHead;
    
    while (k--) {
        
        if (fast) {
            fast =fast -> next;
        }
        else{
            return NULL;
        }
            
    }
    
    while (fast) {
        fast = fast->next;
        low = low -> next;
    }
    return low;
    
}
