//
//  Stack.c
//  括号匹配问题
//
//  Created by zhourenxi on 2022/3/28.
//

#include "Stack.h"

void StackInit(struct Stack  *ps){
    assert(ps);
    ps ->a = NULL;
    ps ->_capacity = 0;
    ps -> _top = 0;
    
}

void StackPush(struct Stack* ps,int x){
    
    assert(ps);
    //扩容
    if (ps ->_top == ps ->_capacity) {
        int newcapacity = (ps -> _capacity == 0) ? 4 : (ps->_capacity*2);
        ps -> a = ( int *)realloc(ps->a, sizeof(int));
        
        if (ps ->a == NULL) {
            printf("realloc  fail");
            exit(-1);
        }
        ps->_capacity = newcapacity;
    }
    ps ->a[ps ->_top]  = x;
    ps ->_top++;
}

void StackPop(struct Stack* ps){//出栈
    
    assert(ps);
    assert(ps ->_top > 0);
    
    ps -> _top--;
}

// 获取栈顶元素,不会导出栈内部等数据
int StackTop(struct Stack* ps){
    
    assert(ps);
    assert(ps ->_top > 0);
    return ps ->a[ps ->_top -1];
}

// 获取栈中有效元素个数
int StackSize(struct Stack* ps){
    
    assert(ps);
    assert(ps ->_top > 0);
    return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(struct Stack* ps){
    return  ps->_top == 0;
}


// 销毁栈
void StackDestroy(struct Stack *ps){
    
    free(ps ->a);
    ps->a = NULL;
    ps ->_top = 0;
    ps -> _capacity = 0;
}


