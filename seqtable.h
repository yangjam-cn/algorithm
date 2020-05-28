/*
 * @Author: youngjam
 * @Date: 2020-04-25 21:01:40
 * @LastEditTime: 2020-04-25 23:29:35
 * @Description:顺序表的结构定义及操作定义
 * @logs: 
    *4.25-->创建文件 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#ifndef SEQTABLE_H
#define SEQTABLE_H

#include"datatype.h"

#define INITSIZE 30     // 定义表的初始长度

typedef enum Status{ERROR, SUCCESS} Status;

/* 顺序表的结构定义 */
typedef struct SeqTable {
    DataType *element;      // 元素项连续存储空间地址
    int length;
}SeqTable, *PtrTable;

/* 初始化顺序表 */
Status InitTable(PtrTable table);

/* 在表尾添加元素 */
Status AddElem(PtrTable table, const DataType *const element, void (*copy)(DataType const *const, DataType *const) );

/* 删除表中自然序为 index 的元素项 */
Status DeleteElem(PtrTable table, int index, void (*copy)(DataType const *const, DataType *const));

/* 寻找表中自然序为 index 的元素项并通过 object 返回 */
Status FindElem(PtrTable table, int index, DataType *object);

/* 删除整个表 */
Status DeleteTable(PtrTable table);

/* 遍历整个表 */
Status TraversalTable(PtrTable table, void (*visit)(DataType const *const) );

/* 返回顺序表的长度 */
int TableLength(PtrTable table);

#endif
