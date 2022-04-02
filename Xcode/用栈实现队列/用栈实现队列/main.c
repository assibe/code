//
//  main.c
//  用栈实现队列
//
//  Created by zhourenxi on 2022/4/1.
//

#include <stdio.h>
#include "MyQueue.h"
#include "Stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
    StackInit(st);
    StackPush(st, 3);
    StackPush(st, 24);
    StackPush(st, 87);
    StackPush(st, 65);
    StackPush(st, 9432);
    StackPush(st,38284);
    int c =  StackTop(st);
    printf("%d\n",c);
    return 0;
}

