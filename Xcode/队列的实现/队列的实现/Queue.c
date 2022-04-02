//
//  Queue.c
//  队列的实现
//
//  Created by zhourenxi on 2022/3/29.
//

#include "Queue.h"

void QueueInit(struct Queue*pq){
    assert(pq);
    
    pq->head = pq->tail =NULL;
}

void QueuePush(struct Queue*pq, STData x){
    assert(pq);
    
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("malloc fail");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    
    if (pq->head == NULL) {
        pq->tail = pq->head = newNode;
        
    }
    else{
        pq->tail->next = newNode;
        pq->tail = pq->tail->next;
    }
}

void QueuePop(struct Queue*pq){
    assert(pq);
    assert(pq->tail&&pq->head);
    
    if (pq->tail->next == NULL) {
        
        free(pq->tail);
        pq->tail =pq->head = NULL;
        
    }
    else{
        struct QueueNode*next = pq->head->next;
        free(pq->head);
        pq->tail = next;
    }
}

STData QueuFront(struct Queue *pq){
    assert(pq);
    assert(pq->tail);
    
    return pq->tail->data;
}

STData QueuBack(struct Queue *pq){
    assert(pq);
    assert(pq->head);
    
    return pq->head->data;
}

void QueueDestroy(struct Queue *pq){
    assert(pq);
    assert(pq->tail&&pq->head);
    
    struct QueueNode*cur = pq->head;
    while (cur) {
        struct QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    
    pq->tail = pq->head = NULL;
}

bool QueuEmpty(struct Queue *pq){
    assert(pq);
    
    return pq->tail == NULL;
}

int QueueSize(struct Queue *pq){
    assert(pq);
    
    int c = 0;
    struct QueueNode *cur = pq->tail;
    while (cur) {
        cur = cur->next;
        c++;
    }
    return c;
}
