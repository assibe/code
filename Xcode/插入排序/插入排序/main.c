//
//  main.c
//  插入排序
//
//  Created by zhourenxi on 2022/4/18.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void InsertSort(int *a,int n){
    
    for (int end = 0 ; end < n-1 ; end ++) {
        
        int tmp = a[end + 1];
        
        while (end >= 0) {
            if (tmp >= a[end]) {
                break;
            }
            else{
                a[end+1] = a[end];
                end--;
            }
        }
        a[end + 1] = tmp;
    }
}

