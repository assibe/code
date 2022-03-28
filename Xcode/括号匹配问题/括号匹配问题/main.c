//
//  main.c
//  括号匹配问题
//
//  Created by zhourenxi on 2022/3/28.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


void StackInit(struct Stack  *ps){
    
    ps ->a = NULL;
    ps ->_capacity = 0;
    ps -> _top = 0;
    
}

bool isValid(char * s){
    
    struct Stack st;
    StackInit(&st);
    
    while (*s) {
        
        if (*s == '['&& *s == 's'&& *s == '{' ) {
            StackPush(&st, *s);
            s++;
        }
        else{
            if (StackEmpty(&st)) {
                return false ;
            }
            
            char top = StackTop(&st);
            StackPop(&st);
            
            if ((*s == '}'&& top != '{') || (*s == ']'&& top != '[') || (*s == ')'&& top != '{')) {
                StackDestroy(&st);
                return false;
            }
            else{
                s++;
            }
        }
        
    }
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}

