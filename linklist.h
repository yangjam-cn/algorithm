/*
 * @Author: youngjam
 * @Date: 2020-04-26 09:33:21
 * @LastEditTime: 2020-04-26 19:38:06
 * @Description:链表结构定义及及函数定义 
 * @logs: 
 * 4.26:创建文件
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#ifndef LINKLIST_H
#define LINKLIST_H
#include"datatype.h"

typedef enum Status {ERROR, SUCCESS} Status;

typedef struct ListNode {
    DataType elem;
    struct ListNode *next;
}ListNode, * PtrNode;

typedef struct LinkList {
    PtrNode head;
    int length;
}LinkList, *PtrList;

/* 初始化一张已存在的表 */
Status InitList(PtrList const llist);

/* 查找表中位序为 index 的元素节点的地址 */
PtrNode FindIndex(PtrList const llist, int index);

/* 将已存在的元素项从表头插入 */
Status AddHead(PtrList const llist, const DataType *const elem, void (*copy)(const DataType *const, DataType *const));

/* 将已存在的元素项从表尾插入 */
Status AddTail(PtrList const llist, const DataType *const elem, void (*copy)(const DataType *const, DataType *const));

/* 将已存在的元素项插入到位序为 index 的元素项后面 */
Status InsertElem(PtrList const llist, const DataType *const elem, int index, void (*copy)(const DataType *const, DataType *const));

/* 删除在表中位序为 index 的元素项 */
Status DeleteElem(PtrList const llist, int index);

/* 删除整张表 */
Status DeleteList(PtrList const llist);

/* 遍历整张表 */
Status TraversalList(const PtrList const llist, void (*visit)(const DataType *const));

/* 获取链表中位序为 index 元素的值 */
Status GetElem(const PtrList const llist, DataType *elem, int index, void (*copy)(const DataType *const, DataType *const));

#endif

