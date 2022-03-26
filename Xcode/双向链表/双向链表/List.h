//
//  List.h
//  双向链表
//
//  Created by zhourenxi on 2022/3/25.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#endif /* List_h */

typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* prev;
}LTNode;

void ListPrint(LTNode* phead);
//void ListInit(LTNode** pphead);


LTNode* BuyLTNode(LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDataType x);

// 在pos之前插入
void ListInsert(LTNode* pos, LTDataType x);

// 删除pos位置的节点
void ListErase(LTNode* pos);

struct ListNode *ListInit(void);
