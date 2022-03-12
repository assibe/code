//
//  contact.h
//  通讯录1
//
//  Created by zhourenxi on 2022/2/14.
//

#ifndef contact_h
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define contact_h

#endif /* contact_h */

#define MAX 1000

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12


typedef struct PeoInfo
{
    char name[NAME_MAX];
    int age;
    char sex[SEX_MAX];
    char addr[ADDR_MAX];
    char tele[TELE_MAX];
}PeoInfo;


//通讯录的结构体
typedef struct Contact
{
    PeoInfo data[MAX];//存放数据
    int sz;//通讯录中有效信息的个数
}Contact;

void InitContact(Contact* pc);//初始化信息

void ShowContact(const Contact* pc);//打印信息

void DeleteContact(Contact* pc);//删除信息

void AddContact(Contact* pc);//增加信息

int FindByName(const Contact* pc, char name[]);//寻找信息
