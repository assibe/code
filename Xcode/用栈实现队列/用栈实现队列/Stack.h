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

#endif /* Stack_h */

struct Stack{
    int *a;
    int _top;
    int _capacity;
};

// 初始化栈
void StackInit(struct Stack  *ps);

// 入栈
void StackPush(struct Stack* ps,int data);

// 出栈
void StackPop(struct Stack* ps);

// 获取栈顶元素
int StackTop(struct Stack* ps);

// 获取栈中有效元素个数
int StackSize(struct Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(struct Stack* ps);

// 销毁栈
void StackDestroy(struct Stack *ps);
