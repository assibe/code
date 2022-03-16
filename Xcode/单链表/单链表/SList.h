//
//  SList.h
//  单链表
//
//  Created by zhourenxi on 2022/3/14.
//

#ifndef SList_h
#define SList_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#endif /* SList_h */

typedef int SLTDataType;

typedef struct SListNode{
    
    SLTDataType data;
    struct SListNode  *next;
    
}SListNode;

void SListPrint(SListNode* phead);//
void SListPushBack(SListNode** pphead, SLTDataType x);//
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopBack(SListNode** pphead);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);

// 在pos位置之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x);
// 删除pos 位置
void SListErase(SListNode** pphead, SListNode* pos);

// 在pos之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 删除pos位置后面的值
void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode** pphead);
