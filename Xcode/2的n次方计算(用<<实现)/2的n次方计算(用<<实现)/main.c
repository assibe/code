//
//  main.c
//  2的n次方计算(用<<实现)
//
//  Created by zhourenxi on 2021/11/30.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int  n = 0;
    scanf("%d",&n);
    n =  2 << (n - 1);
    printf("%d",n);
    return 0;
    
}
