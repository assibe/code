//
//  main.c
//  递归的简单应用
//
//  Created by zhourenxi on 2021/11/3.

#include <stdio.h>

void print(unsigned x);

int main(void){
    unsigned num;
    scanf("%u",&num);
    print(num);
    return 0;
}

void print(unsigned x){
    if (x>9) {
     print(x / 10);
    }
    printf("%d",x%10);
}
