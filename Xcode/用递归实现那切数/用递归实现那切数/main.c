//
//  main.c
//  用递归实现那切数
//
//  Created by zhourenxi on 2021/11/4.
//
#include<stdio.h>
int count(int x){
    if (x<=2) {
        return 1;
    }
    else{
        return count(x-1)+count(x-2);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a , b;
    scanf("%d",&a);
    b = count(a);
    printf("%d",b);
    return 0;
}

