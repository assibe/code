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
    
}
