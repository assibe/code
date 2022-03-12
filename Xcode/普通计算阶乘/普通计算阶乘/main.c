//
//  main.c
//  普通计算阶乘
//
//  Created by zhourenxi on 2021/11/3.
//

#include <stdio.h>

int count(int  x){
    int a , n = 1;
    for (a = 1;a <= x ; a++) {
        n *=a;
    }
    return n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num ,b = 1;
    scanf("%d",&num);
    b = count(num);
    printf("%u",b);
    return 0;
}

