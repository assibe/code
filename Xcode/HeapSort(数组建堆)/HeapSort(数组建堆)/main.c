//
//  main.c
//  HeapSort(数组建堆)
//
//  Created by zhourenxi on 2022/4/7.
//

#include <stdio.h>
#include "Heap.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void HeapSort2(int *a,int size){//从前面进行
    
    for (int i = 0; i < size; i++) {
        AdjustUp(a, i);
    }
}

void Heapsort(int *a,int size){//从后面进行
    
    for (int i =  (size - 1 -1) /2 /*父亲节点*/; i >= 0 ; i--) {
        AdjustDown(a, i, size);//一个小树，一个小树的改变。
        
    }
}
