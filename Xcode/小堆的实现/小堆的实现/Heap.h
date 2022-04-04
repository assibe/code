//
//  Heap.h
//  小堆的实现
//
//  Created by zhourenxi on 2022/4/4.
//

#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#endif /* Heap_h */

typedef int HeapData;

struct Heap{
    HeapData *a;
    int size;
    int capacity;
};

void HeapInit(struct Heap*php);

bool HeapEmpty(struct Heap*php);

size_t HeapSize(struct Heap *php);

HeapData HeapTop(struct Heap *php);

void HeapDestroy(struct Heap *php);

void HeapPrint(struct Heap *php);
