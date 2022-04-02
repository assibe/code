//
//  Stack.c
//  栈的实现
//
//  Created by zhourenxi on 2022/3/27.
//

#include "Stack.h"
void StackInit(struct Stack*ps){
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackPush(struct Stack *ps,STData x){
    assert(ps);
    
    if (ps->top == ps->capacity) {
        int newcapacity = ps->capacity == 0 ?4:ps->capacity*2;
        ps->a = (STData*)realloc(ps->a, newcapacity*sizeof(STData));
        
        if (ps->a == NULL) {
            printf("realloc fail");
            exit(-1);
        }
    }
    ps->a[ps->top] = x;
    ps->top++;
}

STData StackTop(struct Stack*ps){
    assert(ps);
    assert(ps->a);
    
    return ps->a[ps->top - 1];
}

void StackPop(struct Stack*ps){
    assert(ps);
    assert(ps->top >0);
    
    ps->top--;
}

int StackSize(struct Stack *ps){
    assert(ps);
    assert(ps->top>0);
    
    return ps->top;
}

void StackDestroy(struct Stack *ps){
    assert(ps);
    
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

bool StackEmpty(struct Stack*ps){
    assert(ps);
    
    return ps->a == NULL;
}
