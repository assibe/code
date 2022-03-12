//
//  main.c
//  计算某一个年是不是润年
//
//  Created by zhourenxi on 2021/10/31.
//

#include <stdio.h>

int leap(int a){
    if ((0==a%4&&0 != a%100)||(0 == a % 400)) {
        return 1;;
    }
    else{
        return 0;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int year;
    int b;
    scanf("%d",&year);
    b = leap(b);
    if (1==b) {
        printf("是润年");
    }
    else{
        printf("不是润年");
    }
    return 0;
}
