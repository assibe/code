//
//  main.c
//  希尔排序
//
//  Created by zhourenxi on 2022/4/18.
//

#include <stdio.h>
#include <stdlib.h>



void ShellSort(int *a,int n){
    
    int gap = 3;
    for (; gap > 0; gap--) {//间隔可以自选，但是最后肯定必须要有gap == 1，经过一次插入排序
        for (int m = 0; m < gap; m++) {
            
            for (int i = m; i < n - gap; i += gap) {//单层插入
                
                int end = i;
                int tmp = a[end + gap];
                
                while (end >= 0) {
                    
                    if (tmp > a[end]) {
                        break;
                    }
                    else{
                        a[end + gap] = a[end];
                        end -= gap;
                    }
                }
                a[end + gap] = tmp;
            }
            
        }
    }
    
   
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[] = {32,54,65,76,32,12,223,1,234,54,43,32,32,43,32};
    ShellSort(a, sizeof(a)/sizeof(int));
    
    printf("Hello, World!\n");
    return 0;
}

//希尔排序

