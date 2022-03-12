//
//  main.c
//  小乐乐走台阶
//
//  Created by zhourenxi on 2021/11/27.
//

#include<stdio.h>

int coun(int step){//计算乘法
    int  c = 1;
    int b  = 1;
    for (c = 1; c < step+1 ; c++) {
        b *= c;
    }
    return b;
}

int main(void){
    int  step = 0;
    scanf("%d",&step);
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i <= 30; i++) {
        for (j = 0; j <= 30; j++) {
            if (step == i + 2*j) {
                count +=  coun(i + j);
            };
        }
    }
    printf("%d\n",count);
    return 0;
}
