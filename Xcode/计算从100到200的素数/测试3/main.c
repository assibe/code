//
//  main.c
//  测试3
//
//  Created by zhourenxi on 2021/10/30.
//

#include <stdio.h>
#include <math.h>

int prime(int a){
    int b;
    for ( b = 2; b<sqrt(a); b++) {
        if (0==a%b) {
            return 0;
        }
    }
    return 1;
}//计算是否为素数，是输出，输出1。不是输出0.

int main(int argc, const char * argv[]) {
    // insert code here...
    int num ;
    int a;
    for (num = 100; num <201; num++) {
        a = prime(num);
        if (1==a) {
            printf("%d\n",num);
        }
        else if (0!=a){
            break;
        }
    }
  return 0;
}

