//
//  MyQueue.h
//  用栈实现队列
//
//  Created by zhourenxi on 2022/4/2.
//

#ifndef MyQueue_h
#define MyQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

#endif /* MyQueue_h */

typedef struct MyQueue {
    struct Stack *q1;
    struct Stack *q2;
} MyQueue;


MyQueue* myQueueCreate(void);

void myQueuePush(MyQueue* obj, int x);

int myQueuePop(MyQueue* obj);

int myQueuePeek(MyQueue* obj);

bool myQueueEmpty(MyQueue* obj);

void myQueueFree(MyQueue* obj);
