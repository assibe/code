//
//  main.c
//  判断整数奇偶性
//
//  Created by zhourenxi on 2021/11/14.
//

#include<stdio.h>
int main(){
    int n = 0;
    while(scanf("%d",&n) != EOF){
        if(0 == n%2){
            printf("Even\n");
        }
        else{
            printf("Odd\n");
        }
    }
    return 0;
}
