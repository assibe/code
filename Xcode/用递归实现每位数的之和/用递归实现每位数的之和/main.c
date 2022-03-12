//
//  main.c
//  用递归实现每位数的之和
//
//  Created by zhourenxi on 2021/11/3.
//

#include <stdio.h>
int  DigitSum(int n){
    if (n > 10) {
        return n%10+DigitSum(n/10);
    }
    else
        return n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a;
    scanf("%d",&a);
    int b ;
    b =  DigitSum(a);
    printf("%d",b);
    return 0;
}
