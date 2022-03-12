//
//  main.c
//  考试
//
//  Created by zhourenxi on 2021/11/28.
//

#include <stdio.h>
long test(long a,long  b){
    if (a < b) {
        long  i = a;
        a = b;
        b = i;
    }
    long i ;
    for (i = 0; i*b <= a; i++) {
        if (i * b == a) {
            return a;
        }
    }
    long arr1[100000] = {0};
    long arr2[100000] = {0};
    for (i = 1; i <= a; i++) {//计算a的供述
        if (0 == a % i) {
            arr1[i] = i;
        }
    }
    for (i = 1; i <= b; i++) {//计算b的供述
        if (0 == b % i) {
            arr2[i] = i;
        }
    }
    int  j = a;
    int   c= b;
    for (c = b; c >= 1; c--) {
        printf("dfaf");
    }
//    while (j > 0) {
//        while (c > 0) {
//            if (arr1[j] == arr2[c] && arr1[j] != 0) {
//                break;
//            }
//            else
//                c--;
//        }
//        if (arr1[j] == arr2[c] && arr1[j] != 0) {
//            break;
//        }
//        j--;
//        c = b;
//    }
    return (a*b)/arr1[j];
 }

int main(int argc, const char * argv[]) {
    // insert code here...
    long a = 0;
    long  b = 0;
    scanf("%lu %lu",&a,&b);
    long m = 0;
    m = test(a,b);
    printf("%ld",m);
    return 0;
}
