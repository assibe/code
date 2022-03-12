//
//  main.c
//  模拟实现strlen
//
//  Created by zhourenxi on 2022/1/22.

#include <stdio.h>

unsigned my_strlen(const char *str){
   unsigned int n = 0;
    while (*str++ != '\0') {
        n++;
    }
    return n;
}

int main(void){
    char n[] = {"falnsfa"};
    printf("%d",my_strlen(n));
    return 0;
}
