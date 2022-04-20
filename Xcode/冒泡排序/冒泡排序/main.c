//
//  main.c
//  冒泡排序
//
//  Created by zhourenxi on 2022/4/19.
//

#include <stdio.h>

void BubbleSort(int *a,int n){
    
    for (int i = 0; i < n; i++) {
        
        for (int c = 1; c < n - i; c++) {
            
            if (a[c - 1] < a[c]) {//改变的方向可以改变排序的升降序
                
               int  tmp = a[c - 1];
                a[c - 1] = a[c];
                a[c ] = tmp;
                
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[] = {12,34,43,54};
    BubbleSort(a, sizeof(a)/sizeof(int));
    
    printf("Hello, World!\n");
    return 0;
}

