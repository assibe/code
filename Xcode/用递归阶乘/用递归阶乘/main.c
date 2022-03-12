//
//  main.c
//  用递归阶乘
//
//  Created by zhourenxi on 2021/11/3.
//

#include <stdio.h>

int recu(int x);

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 0,b = 0;
    scanf("%d",&a);
    b = recu(a);
    printf("%d",b);
    return 0;
}
int  recu(int x){
    if (1==x) {
        return  1;
    }
    else
        return x*recu(x-1);
}
