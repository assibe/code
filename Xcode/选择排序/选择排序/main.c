//
//  main.c
//  选择排序
//
//  Created by zhourenxi on 2022/4/28.
//

#include <stdio.h>
#include <stdlib.h>


void Swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int *a,int n){
    
    int max = n - 1;
    int min = 0;
    int tmp = 0;
    
    for (int i = 0; i < n; i++) {
        
        tmp = i;
        while (tmp < n - i) {//单次循环
            
            if (a[tmp] > a[max]) {
                Swap(&a[tmp],&a[max]);
            }
            
            if (a[tmp] < a[min]) {
                Swap(&a[tmp], &a[min]);
            }
            tmp++;
        }
        min++;
        max--;
    }
       
    
    
}






int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {12,32,43,54,23,43,345,54};
    SelectSort(a, sizeof(a)/sizeof(int));
    
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ",a[i]);
    }
    printf("Hello, World!\n");
    return 0;
}

