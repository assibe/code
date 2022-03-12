//
//  main.c
//  打印乘法表
//
//  Created by zhourenxi on 2021/10/31.
//

#include <stdio.h>

void stamp (int x){
    int a = 0,b = 0;
    for (a = 1; a <= x; a++) {
        for (b = 1; b <= a; b++) {
            printf("%d*%d = %2d  ",a,b,a*b);
            if (b==a) {
                printf("\n");
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    scanf("%d",&num);
    stamp(num);
    return 0;
}
