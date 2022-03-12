//
//  main.c
//  压栈测试
//
//  Created by zhourenxi on 2021/11/21.
//

#include <stdio.h>
int Ad(int ,int );

int main(void) {
    // insert code here...
    int a = 10;
    int c = 0;
    int m = 1323342;
    int b = 123;
    m = Ad(a, c);
    printf("%d\n",a);
    printf("oiaogs");
    return 0;
}

int Ad(int a,int b){
    int c = a+b;
    return c;
}
