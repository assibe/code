//
//  Stack.h
//  栈的实现
//
//  Created by zhourenxi on 2022/3/27.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#endif /* Stack_h */


typedef int STData;

struct Stack{
    STData *a;
    int top;
    int capacity;
};

void StackInit(struct Stack*ps);

void StackPush(struct Stack *ps,STData x);

STData StackTop(struct Stack*ps);

void StackPop(struct Stack*ps);

int StackSize(struct Stack *ps);

void StackDestroy(struct Stack *ps);

bool StackEmpty(struct Stack*ps);
