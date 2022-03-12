//
//  main.c
//  求两个数二进制中不同位的个数
//
//  Created by zhourenxi on 2021/11/12.
//
#include<stdio.h>
int main(void){
    int input1;
    int input2;
    scanf("%d%d",&input1,&input2);
    int c = input1 ^ input2;
    int i = 0;
    int total = 0;
    for(i = 0; i < 32; i++){
        if(1 == (c&1)){
            total++;
        }
        c = c>>1;
    }
    printf("%d",total);
    return 0 ;
}
