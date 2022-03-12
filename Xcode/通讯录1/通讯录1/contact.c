//
//  contact.c
//  通讯录1
//
//  Created by zhourenxi on 2022/2/14.
//

#include "contact.h"

void InitContact(Contact* pc){
    assert(pc);//判断是否为空指针
    memset(pc->data, 0, sizeof(pc->data));
}
//初始化

void ShowContact(const Contact* pc){
    assert(pc);
    printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话","地址");
    for (int i = 0; i < pc->sz; i++) {
        printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele,pc->data[i].addr);
    }
}
//打印结束

int FindByName(const Contact* pc, char name[]){
    int i = 0;
    for (i = 0; i < pc->sz; i++) {
        if (strcmp(pc->data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
//寻找信息的函数

void DeleteContact(Contact* pc){
    
    char name[NAME_MAX] = {0};
    assert(pc);
    if (pc->sz == 0) {
        printf("通讯录为空");
        return;
    }
    printf("请输入要删除人的名字");
    scanf("%s",name);
    
    int pos = FindByName(pc, name);
    if (pos == -1) {
        printf("成员不存在");
        return;
    }
    else{
                int j = 0;
                for (j = pos; j < pc->sz-1; j++)
                {
                    pc->data[j] = pc->data[j + 1];
                }
                pc->sz--;

                printf("删除指定联系人成功\n");
            }
    }
//删除信息

void AddContact(Contact* pc){
    assert(pc);
    if (pc->sz == MAX) {
        printf("输入已满");
        return;
    }
    else{
        printf("请输入名字:>");
            scanf("%s", pc->data[pc->sz].name);
            printf("请输入年龄:>");
            scanf("%d", &(pc->data[pc->sz].age));
            printf("请输入性别:>");
            scanf("%s", pc->data[pc->sz].sex);
            printf("请输入电话:>");
            scanf("%s", pc->data[pc->sz].tele);
            printf("请输入地址:>");
            scanf("%s", pc->data[pc->sz].addr);

            pc->sz++;
            printf("增加联系人成功\n");
    }
}
//增加信息
