//
//  main.c
//  公务员面试
//
//  Created by zhourenxi on 2021/11/30.
//

#include <stdio.h>

int MAX(const int *arr){//计算最大值
    int c = *arr;
    int i = 0;
    for (i = 0; i < 7; i++) {
        if (c < *(arr + i) ) {
            c = *(arr +i);
        }
    }
    return c;
}



int MIN(const int *arr){//计算最小值
    int c = *arr;
    int i = 0;
    for (i = 0; i <  7; i++) {
        if (c > *(arr + i) ) {
            c = *(arr +i);
        }
    }
    return c;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[7] = { 0 };
    for (int i = 0; i < 7; i++) {
        scanf("%d ",&arr[i]);
    }
    int b = MAX(arr);
    int c = MIN(arr);
    int conut = 0;
    int  i = 0;
    for (i = 0; i < 7; i++) {
        conut += arr[i];
    }
    float aver = (float)conut - (float)b - (float)c;
    printf("%.2f\n",aver/5.0);
    return 0;
}
