//
//  main.c
//  用递归实现n的k次方阶参
//
//  Created by zhourenxi on 2021/11/4.
//

#include <stdio.h>
int power(int a,int b){
    if (b!=1) {
        return a*power(a, b-1);
    }
    else{
        return a;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 0,b = 0,c = 0;
    scanf("%d %d",&a,&b);
    c = power(a,b);
    printf("%d",c);
    return 0;
}
