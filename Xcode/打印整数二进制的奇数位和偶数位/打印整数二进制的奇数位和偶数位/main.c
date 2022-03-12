//
//  main.c
//  打印整数二进制的奇数位和偶数位
//
//  Created by zhourenxi on 2021/11/12.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int input  = 0;
    scanf("%d",&input);
    int i = 0;
    for (i = 0; i < 32; i++) {
        
        if (1 == ((input>>i)&1)) {
            printf("奇数位：第%d位\n",i);
        }
        else{
            printf("偶数位为%d\n",i);
        }
    }
    return 0;
}
