//
//  MyQueue.c
//  用栈实现队列
//
//  Created by zhourenxi on 2022/4/2.
//

#include "MyQueue.h"

MyQueue* myQueueCreate(void){
    
    struct MyQueue* BuyMyQueue = malloc(sizeof(MyQueue));
    if (BuyMyQueue == NULL) {
        printf("malloc fail");
        return NULL;
    }
    BuyMyQueue ->q1 = malloc(sizeof(struct Stack));
    if (BuyMyQueue->q1 == NULL) {
        printf("malloc fail");
        return NULL;
    }
    BuyMyQueue ->q2 = malloc(sizeof(struct Stack));
    if (BuyMyQueue->q2 == NULL) {
        printf("malloc fail");
        return NULL;
    }
    return BuyMyQueue;
}

void myQueuePush(MyQueue* obj, int x){
    assert(obj);
    
    if (obj->q1 != NULL) {
        StackPush(obj ->q1, x);
    }
    else{
        StackPush(obj ->q2, x);
    }

}

int myQueuePop(MyQueue* obj){
    assert(obj);
    
    struct Stack *NonEmpty = obj->q1;
    struct Stack *Empty = obj->q2;
    
    while (StackSize(Empty) >1) {
        int c = StackTop(Empty);
        StackPop(Empty);
        StackPush(NonEmpty, c);
    }
    
    int c = StackTop(Empty);
    StackPop(Empty);
    return c;
    
}

int myQueuePeek(MyQueue* obj){
    assert(obj);
    
    struct Stack *NonEmpty = obj->q1;
    struct Stack *Empty = obj->q2;
    
    while (StackSize(Empty) >1) {
        int c = StackTop(Empty);
        StackPop(Empty);
        StackPush(NonEmpty, c);
    }
    
    int c = StackTop(Empty);
    StackPop(Empty);
    StackPush(NonEmpty, c);
    
    return c;
}


bool myQueueEmpty(MyQueue* obj){
    assert(obj);
    if (obj->q1 == NULL&&obj->q2 == NULL) {
        return false;
    }
    else
        return true;
    
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    
    free(obj->q1);
    obj->q1 =NULL;
    free(obj->q2);
    obj->q2 =NULL;
    free(obj);
}

