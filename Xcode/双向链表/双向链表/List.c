//
//  List.c
//  双向链表
//
//  Created by zhourenxi on 2022/3/25.
//

#include "List.h"

LTNode* BuyLTNode(LTDataType x){//创建新的数组
    LTNode *newnode = malloc(sizeof(LTNode));
    
    if (NULL == newnode) {
        printf("创建失败");
        exit(-1);
    }
    newnode ->data = x;
    newnode ->prev = NULL;
    newnode -> next = NULL;
    
    return newnode;
}


void ListPrint(LTNode* phead){//打印
    
    assert(phead);
    LTNode *cur = phead;
    while (cur->next != phead) {
        printf("%d",cur ->data);
        cur = cur -> next;
    }
    printf("\n");
    
}

void ListInsert(LTNode* pos, LTDataType x){//插入
    
    assert(pos);
    
    LTNode *cur = malloc(sizeof(LTNode));
    LTNode *nxt = pos -> prev;
    
    nxt -> next = pos;
    cur -> prev = nxt;
    
    cur ->next = pos;
    pos -> prev = cur;
}

void ListErase(LTNode* pos){//删除
    
    assert(pos);
    pos ->prev ->next = pos -> next;
    pos -> next ->prev = pos -> prev;
    free(pos);
    pos = NULL;
}

struct ListNode *ListInit(void){
    
    LTNode *phead = BuyLTNode(0);
    phead ->next = phead;
    phead ->prev = phead;
    return phead;
}

LTNode* ListFind(LTNode* phead, LTDataType x){
    
    assert(phead);
    LTNode *cur = phead;
    while (cur->data != x) {
        cur = cur -> next;
    }
    return cur;
}
