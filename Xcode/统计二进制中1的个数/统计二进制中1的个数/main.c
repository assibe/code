//
//  main.c
//  统计二进制中1的个数
//
//  Created by zhourenxi on 2021/11/12.
//
#include <stdio.h>

int NumberOf1(int n ) {
    // write code here
    int i = 0;
    int total = 0;
    for(i = 0; i <32;i++){
        if(1 == (n&1)){
            total++;
        }
        n = n>>1;
    }
    return total;
}
