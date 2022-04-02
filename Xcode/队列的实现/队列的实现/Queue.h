//
//  Queue.h
//  队列的实现
//
//  Created by zhourenxi on 2022/3/29.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#endif /* Queue_h */
typedef int  STData;

struct QueueNode{
    
    STData data;
    struct QueueNode*next;
};

struct Queue{
    struct QueueNode *tail;
    struct QueueNode *head;
};

void QueueInit(struct Queue*pq);

void QueuePush(struct Queue*pq, STData x);

void QueuePop(struct Queue*pq);

STData  QueuFront(struct Queue *pq);

STData QueuBack(struct Queue *pq);

void QueueDestroy(struct Queue *pq);

bool QueuEmpty(struct Queue *pq);

int QueueSize(struct Queue *pq);
