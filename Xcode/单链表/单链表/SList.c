//
//  SList.c
//  单链表
//
//  Created by zhourenxi on 2022/3/14.
//

#include "SList.h"


void SListPrint(SListNode* phead){
    
    SListNode *cur = phead;
    if (cur == NULL) {
        return;
    }
    while (cur) {
        printf("%d ->",cur -> data);
        cur = cur->next;
    }
}

SListNode* SListFind(SListNode *phead, SLTDataType x){
   
    assert(phead);
    SListNode * cur = phead;
    while (cur != NULL) {
        
        if (cur ->data == x) {
            return cur;
        }
        else{
            cur = cur -> next;
            
        }
    }
    return NULL;
}

SListNode *MakeSListNode(SLTDataType x){//创建一个结构体，赋值x

    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    
    if (newnode == NULL) {
        printf("创建失败");
        exit(-1);
        
//        是分别返回1和-1到主调程序。
//        exit(0)则是返回0。
//        exit(0)表示程序正常退出，非0表示非正常退出
    }
    else{
        newnode -> data =  x;
        newnode -> next = NULL;
    }
    return newnode;
}


void SListPushBack(SListNode** pphead, SLTDataType x){
    
    assert(pphead);
    if (*pphead == NULL) {
        *pphead = MakeSListNode(x);
    }
    
    else if ((*pphead) -> next == NULL){
        *pphead = MakeSListNode(x);
    }
    
    else{
        
        while ((*pphead) -> next != NULL)  {
            *pphead = (*pphead) -> next;
        }
        (*pphead)->next = MakeSListNode(x);
        
    }
}

void SListPopFront (SListNode** pphead){
    
    assert(pphead);
    
    if (*pphead == NULL) {
        return;
    }
    else{
        SListNode *next = (*pphead) -> next;
        free(*pphead);
       *pphead = next;
    }
}


void SListInsertBefore(SListNode** pphead, SListNode* pos, SLTDataType x){
    
    assert(pphead);
    assert(pos);
    
    if (*pphead == pos) {
        SListPushBack( pphead, x);
    }
    else{
        
        SListNode **cur = pphead;
        for (; (*cur) ->next != pos; *cur = (*cur)->next);
        (*pphead) -> next  = MakeSListNode(x);
        (*pphead) -> next -> next = pos;
    }
}

void SListErase(SListNode **pphead,SListNode *pos){
    
    assert(pphead);
    assert(pos);
    
    if (*pphead == pos) {
        SListPopFront(pphead);
    }
    else{
        
        SListNode *prev = *pphead;
        while (prev -> next != pos) {
            prev = prev -> next;
        }
        prev -> next = pos ->next;
        free(pos);
        pos = NULL;
    }
}

void SlistInsertAfter(SListNode *pos,SLTDataType x){
   
    assert(pos);
    SListNode *cur = pos ->next;
    pos->next = MakeSListNode(x);
    pos -> next -> next = cur;
    
}

void SListEraseAfter(SListNode *pos){
    
    assert(pos);
    if (pos -> next) {
        SListNode *cur = pos -> next;
        pos->next = pos->next ->next;
        free(cur);
    }
   
}

void SListDistroy(SListNode** pphead){
    
    assert(pphead);
    SListNode *cur = *pphead;
    while (cur) {
        
        SListNode *next = cur ->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}
