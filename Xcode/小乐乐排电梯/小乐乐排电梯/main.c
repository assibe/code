//
//  main.c
//  小乐乐排电梯
//
//  Created by zhourenxi on 2021/11/29.
//

#include<stdio.h>
int main(void){
    long nmber = 0;
    scanf("%ld ",&nmber);
    int time = 2;
    if ( 0 != nmber / 12) {
        time += (nmber/12*4);
    }
    printf("%d",time);
    return 0;
}
