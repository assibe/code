//
//  main.c
//  合并两个有序链表
//
//  Created by zhourenxi on 2022/3/21.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


struct ListNode {
    
    int val;
    struct ListNode *next;
    
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if (list1 == NULL) {
        
        return list1;
    }
    else{
        if (list2) {
            return list2;
        }
    }
    
    struct ListNode *head = NULL,*tail = NULL;
}
