//
//  main.c
//  打印水仙花数
//
//  Created by zhourenxi on 2021/11/19.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = 0;
    for (i = 0; i <= 100000; i++) {
        int a = 0,b = 0,c = 0,d = 0,e = 0;
        a = i % 10;
        b = i % 100/10;
        c = i % 1000/100;
        d = i % 10000/1000;
        e = i % 100000/10000;
        int n = 0;
        for (n = 0; n <= i; n++) {
            if (i == pow(a,n) + pow(b, n) +pow(c, n) +pow(d, n) +pow(e, n) ) {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
