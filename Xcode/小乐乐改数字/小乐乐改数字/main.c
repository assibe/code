//
//  main.c
//  小乐乐改数字
//
//  Created by zhourenxi on 2021/11/27.
//

#include<stdio.h>
int main(){
    long count = 0;
    scanf("%ld",&count);
    long a = 10000000000;
    long b = 0;
    long m = 0;
    while (1) {
         m = count/a;
        if (1 == m%2) {
            b += a;
        }
        count %= a;
        a /= 10;
        if (a == 1) {
            if (1 == count%2) {
                b += 1;
            }
            break;
        }
    }
    
    printf("%-ld",b);
    return 0;
}
