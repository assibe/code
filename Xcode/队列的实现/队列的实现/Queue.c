//
//  Queue.c
//  队列的实现
//
//  Created by zhourenxi on 2022/3/29.
//

#include "Queue.h"

void QueueInit(Queue* pq){//初始化
    
    assert(pq);
    pq ->tail = pq -> tail = NULL;
}

void QueuePop(Queue* pq){
    
    assert(pq);
    assert(pq ->head &&pq ->tail);
    QNode *next = pq -> head -> next;
    free(pq ->head);
    pq -> head = next;
    
}

void QueueDestory(Queue* pq){
    
    assert(pq);
    QNode *cur = pq ->head;
    while (cur) {
        
        cur = cur->next;
        free(pq ->head);
        pq -> head = cur;
    }
    
    free(pq);
    pq = NULL;
    pq ->head = pq -> tail = NULL;
}

QNode *MakeNode(QDataType x){
    
    QNode * cur = malloc(sizeof(QNode));
    assert(cur);
    cur ->data = x;
    cur ->next = NULL;
    return cur;
}

void QueuePush(Queue* pq, QDataType x){
    
    if (pq ->head == NULL ) {
        pq -> head = pq -> tail = MakeNode(x);
    }
    else{
        pq -> tail -> next = MakeNode(x);
        pq -> tail = pq ->tail ->next;
    }
}

void QueuePoP(Queue* pq){
    
    assert(pq);
    assert(pq ->head&&pq -> tail);
    if (pq -> head ->next == NULL) {
        free(pq ->head);
        pq ->head = pq ->tail = NULL;
    }
    else{
        QNode *next = pq -> head -> next;
        free(pq ->head);
        pq -> head = next;
    }
    
}

bool QueueEmpty(Queue* pq){
    assert(pq);
    return pq -> head ==NULL;
}

size_t QueueSize(Queue* pq){
    
    assert(pq);
    QNode *cur = pq -> head;
    size_t Size = 0;
    while (cur) {
        Size++;
        cur = cur ->next;
    }
    
    return Size;
}

QDataType QueueFront(Queue* pq){
    
    assert(pq);
    assert(pq -> head);
    return pq ->head ->data;
    
}

QDataType QueueBack(Queue* pq){
    
    assert(pq);
    assert(pq ->head);
    
    return pq -> tail ->data;
}

