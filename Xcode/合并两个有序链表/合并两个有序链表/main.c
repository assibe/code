//
//  main.c
//  合并两个有序链表
//
//  Created by zhourenxi on 2022/3/21.
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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if (list1  == NULL) {
        
        return list2;
        
    }
    else{
        
        if (list2 == NULL) {
            return list1;
        }
        
    }
    
    struct ListNode *head = NULL,*tail = NULL;
    head = tail = (struct ListNode *)malloc(sizeof(struct ListNode ));
    head ->next =NULL;
    
    while (list1 &&list2) {
        
        if (list1 ->val > list2->val) {
            
            tail -> next = list2;
            tail = tail -> next;
            
            list2 = list2->next;
            
        }
        else{
            
            tail -> next = list2;
            tail = tail -> next;
            
            list1 = list1 -> next;
            
        }
        
    }
    
    if (list2) {
        
        tail -> next = list2;
        
    }
    else
        tail -> next = list1;
    
    struct ListNode * list = head ->next;//不是从第一个点进行的相关内容
    free(head);
    
    return list;
    
    
}
