//
//  Heap.c
//  小堆的实现
//
//  Created by zhourenxi on 2022/4/4.
//

#include "Heap.h"

void HeapInit(struct Heap*php){
    php->a = NULL;
    php->size = 0;
    php->capacity = 0;
}


bool HeapEmpty(struct Heap*php){
    assert(php);
    return php->size == 0;
}

size_t HeapSize(struct Heap *php){
    
    assert(php);
    return php->size;
}

HeapData HeapTop(struct Heap *php){
    assert(php);
    assert(php->size>0);
    return php->a[0];
}

void HeapDestroy(struct Heap *php){
    assert(php);
    
    free(php->a);
    php->capacity = php->size = 0;
}


void HeapPrint(struct Heap *php){
    assert(php);
    
    int n = 0;
    while (n<php->size) {
        
        printf("%d",php->a[n]);
        n++;
    }
}


void AdjustUp(HeapData *pa,size_t child){
    
    size_t parent = (child -1)/2;
    
    while (parent > 0) {
        
        if (pa[parent]<pa[child]) {
            
            int tmp = pa[child];
            pa[child] = pa[parent];
            pa[parent] = tmp;
            
            child = parent;
            parent = (child - 1)/2;
        }
        else
            break;
    }
}



void HeapPush(struct Heap *php,HeapData x){
    assert(php);
    
    if (php->size == php->capacity) {//判断是否扩容
        
        size_t newcapacity = php->capacity == 0?4:php->capacity*2;
        HeapData *tmp = realloc(php->a, sizeof(HeapData));
        
        if (tmp == NULL) {
            printf("reamlloc fail");
            exit(-1);
        }
        
        php->a = tmp;
        php->capacity = newcapacity;
    }
    
    php->a[php->size++] = x;
    
    AdjustUp(php->a, php->size -1);
}

void AdjustDown(HeapData*a,size_t size,size_t root){//root为调制开始的位置
    
    size_t parent = root;
    size_t child = parent *2 + 1;
    
    while (child < size) {
        
        if (child + 1 < size && a[child + 1] < a[child]) {
            HeapData tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;
            
            parent = child;
            child = parent*2 - 1;
            
        }
        else
            break;
    }
}


void HeapPop(struct Heap*php){
    assert(php);
    
    HeapData tmp = php->a[0];
    php->a[0]  = php->a[php->size-1];
    php->a[(php->size--)-1] = tmp;
    
    AdjustDown(php->a,php->size,0);
    
}

void HeapSort(HeapData *a,size_t size){//堆排序
    struct Heap hp ;
    HeapInit(&hp);
    for (int  i = 0; i < size; i++) {
        HeapPush(&hp, a[i]);
    }
    
    size_t j = 0;
    while (!HeapEmpty(&hp)) {
        
        a[j++] = HeapTop(&hp);
        HeapPop(&hp);
    }
    HeapDestroy(&hp);
}
