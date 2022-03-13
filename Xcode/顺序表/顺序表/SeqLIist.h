
//
//  SeqLIist.h
//  顺序表
//
//  Created by zhourenxi on 2022/3/13.
//

#ifndef SeqLIist_h
#define SeqLIist_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#endif /* SeqLIist_h */

typedef int SLDateType;
 
typedef struct SeqList{
    
    SLDateType *a;//数据
    size_t size;//个数
    size_t capacity;//大小
    
}SeqList;

void SeqListInit(SeqList* psl);
void SeqListDestory(SeqList* psl);
 
void SeqListPrint(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDateType x);
void SeqListPushFront(SeqList* psl, SLDateType x);
void SeqListPopFront(SeqList* psl);
void SeqListPopBack(SeqList* psl);
 
// 顺序表查找

int SeqListFind(SeqList* psl, SLDateType x);

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDateType x);

// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);
