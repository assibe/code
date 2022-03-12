//
//  main.c
//  指针打印数组内容
//
//  Created by zhourenxi on 2021/11/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {12,342,424,2314,242,424};
    int* p = &arr[1];
    int n = sizeof(arr)/sizeof(arr[1]);
    int i = 0;
    for (i = 0; i < n-1; i++) {
        printf("%d\n",*(p +i));
    }
    return 0;
}
