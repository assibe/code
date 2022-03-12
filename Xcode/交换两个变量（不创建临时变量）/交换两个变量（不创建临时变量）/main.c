//
//  main.c
//  交换两个变量（不创建临时变量）
//
//  Created by zhourenxi on 2021/11/12.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    scanf("%d %d",&a,&b);
    a = a^b;
    b = a^b;
    a = b^a;
    return 0;
}
