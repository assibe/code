//
//  SeqLIist.c
//  顺序表
//
//  Created by zhourenxi on 2022/3/13.
//

#include "SeqLIist.h"

void SeqListInit(SeqList* psl){
    
    assert(psl);
    
    psl -> capacity = 0;
    psl -> size = 0;
    psl -> a = NULL;
}

void SeqListDestory(SeqList* psl){
    assert(psl);
    
    free(psl ->a);
    psl -> a = NULL;
    psl -> capacity = 0;
    psl -> size = 0;
    
}

void SeqListPrint(SeqList* psl){
    
    for (int n = 0; n < psl -> size; n++) {
        printf("%d",psl -> a[n]);
    }
    printf("\n");
    
}

void SeqListPushBack(SeqList* psl, SLDateType x){
    
    assert(psl);
    psl -> a[psl -> size] = x;
    psl -> size++;
    psl -> capacity++;
}

void SeqListPushFront(SeqList* psl, SLDateType x){
    
    assert(psl);
    psl -> capacity++;
    psl -> size++;
    
    for (unsigned long n = psl -> size - 2; n >= 0; n--) {
        psl -> a[n + 1] = psl -> a[n];
    }
    
    psl -> a[0] = x;
}

void SeqListPopFront(SeqList* psl){
    
    assert(psl);
    if (psl -> size > 0) {
        
        int begin = 1;
        for (begin = 1; begin < psl -> size; begin++) {
            psl -> a[begin -1] = psl -> a[begin];
        }
    }
    psl -> size--;
}

void SeqListPopBack(SeqList* psl){
    
    assert(psl);
    
    psl -> a[psl -> size -1] = 0;
    if (psl -> size > 0) {
        psl -> size--;
    }
    
}


int SeqListFind(SeqList* psl, SLDateType x){
   
    for (int n = 0; n < psl -> size; n++) {
        if (psl -> a[n] == x) {
            return n;
        }
    }
    return -1;
}

void SeqListErase(SeqList* psl, size_t pos){
    
    assert(psl);
    assert(psl -> size > pos);
    
    for (size_t n = pos; n < psl -> size; n++) {
        
        psl -> a[n] = psl -> a[n + 1];
        
    }
    psl -> size--;
}
