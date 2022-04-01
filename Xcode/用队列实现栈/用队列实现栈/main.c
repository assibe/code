//
//  main.c
//  用队列实现栈
//
//  Created by zhourenxi on 2022/3/30.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define QDataType int

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}



typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;

    //size_t size;
}Queue;

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
//-----------------------------------------------------------------------------------------



typedef struct {

    Queue q1;
    Queue q2;
    
} MyStack;


MyStack* myStackCreate(void) {
    
    MyStack *st = malloc(sizeof(MyStack));
    if (st == NULL) {
        return NULL;
    }
    QueueInit(&st ->q1);
    QueueInit(&st ->q2);
    
    return st;
}

void myStackPush(MyStack* obj, int x) {
    
    
    assert(obj);
    if (!QueueEmpty(&obj ->q1)) {
        QueuePush(&obj->q1, x);
    }
    else{
        QueuePush(&obj ->q2, x);
    }
    
}

int myStackPop(MyStack* obj) {
    
    assert(obj);
    Queue *emptyQ = &obj -> q1;
    Queue *nonEmptyQ = &obj -> q2;
    
    while (QueueSize(emptyQ) > 1) {
        
        int fornt = QueueFront(emptyQ);
        QueuePush(nonEmptyQ, fornt);
        QueuePop(emptyQ);
        
    }
    
    int top = QueueFront(nonEmptyQ);
    QueuePop(nonEmptyQ);
    
    return top;
    
}

int myStackTop(MyStack* obj) {
    
    assert(obj);
    
    int Top = QueueBack(&obj->q1);
    QueuePop(&obj->q1);
    
    return Top;
    
}

bool myStackEmpty(MyStack* obj) {
    assert(obj);
    
    return QueueEmpty(&obj ->q1) && QueueEmpty(&obj ->q2);
}

void myStackFree(MyStack* obj) {
    assert(obj);
    
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
}
