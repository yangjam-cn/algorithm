/*
 * @Author: youngjam
 * @Date: 2020-04-25 20:18:24
 * @LastEditTime: 2020-04-26 19:56:52
 * @Description: 测试代码文件
 *  @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include<stdlib.h>
#include<stdio.h>
// #include"datatype.h"
// #include"seqtable.h"
#include"linklist.h"

int main(void)
{
    DataType student;
    PtrList llist = (PtrList)malloc(sizeof(LinkList));
    if (llist != NULL)
        printf("%p\n", llist);
    // free(llist);
    InitList(llist);
    for (int i = 0;  i < 2;  i++){
        GetData(&student);
        AddHead(llist, &student, CopyData);
    }
    for (int i = 0;  i < 2;  i++){
        GetData(&student);
        AddTail(llist, &student, CopyData);
    }
    GetData(&student);
    InsertElem(llist, &student, 2, CopyData);
    TraversalList(llist, PrintData);
    DeleteElem(llist, 1);
    TraversalList(llist, PrintData);
    GetElem(llist, &student, 2, CopyData);
    printf("\n");
    PrintData(&student);
    DeleteList(llist);
    free(llist);
    return 0;
}