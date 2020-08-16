/*
 * @Author: youngjam
 * @Date: 2020-04-26 10:22:12
 * @LastEditTime: 2020-04-26 19:54:36
 * @Description:链表的实现 
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include"linklist.h"
#include<stdlib.h>
#include<stdio.h>
/**
 * @description: 检查malloc函数分配地址是否成功
 * @input: malloc 分配的地址
 * @output: 返回状态标志；若失败会打印输出信息
 */
Status CheckMalloc(void *ptr)
{
    if (ptr == NULL) {

        printf("memory allocation failure!\n");
        return ERROR;
    }   // end if
    return SUCCESS;
}   // end


/**
 * @description: 生成新的链表节点
 * @input: 
 * elem：已存在的元素项
 * copy：元素项操作函数，将一个元素项复制给另一个
 * @output: 
 */
PtrNode NewNode(const DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    PtrNode node = (PtrNode)malloc(sizeof(ListNode));

    if (CheckMalloc(node)) {    // 检查分配地址是否成功

        (*copy)(elem, &(node->elem));
        node->next = NULL;
        return node;
    }   // end if
    return NULL;
}   // end


/**
 * @description: 初始化链表
 * @input:  已存在的链表指针
 * @output: 生成链表头节点并将其长度置 0 ,头节点数据域悬空
 */
Status InitList(PtrList const llist)
{
    if (llist != NULL) {    //  检查表指针是否为空

        llist->head = (PtrNode)malloc(sizeof(ListNode));

        if (CheckMalloc(llist->head)) {     // 检查分配地址

            llist->head->next = NULL;
            llist->length = 0;
            return SUCCESS;     // 正常 return
        }   // end if
        return ERROR;
    }   // end if

    return ERROR;
}


/**
 * @description: 寻找位序为 index 的元素项的地址
 * @input: 
 * llist:链表指针
 * index:元素项在表中的位序(不含头节点，1~length)
 * @output: 位序为 index 的元素项的地址
 */
PtrNode FindIndex(PtrList const llist, int index)
{
    if (llist != NULL) {

        if (index > 0 && index <= llist->length ) {     // 检查 index 是否合法

            PtrNode ptr = llist->head;

            for (int i = 1;  i <= index;  i++)      // 从头节点开始移动，故至少移动一次
                ptr = ptr->next;
            
            return ptr;     // 正常 return
        }   // end if
    }   // end if
    return NULL;   
}   // end


/**
 * @description: 从表头插入元素项 elem
 * @input: 
 * llist：链表指针
 * elem：元素项指针
 * copy：数据项操作函数指针，将元素项复制给另一同型变量
 * @output: 在表头插入元数项
 */
Status AddHead(PtrList const llist, const DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (llist != NULL) {

        PtrNode new_node = NewNode(elem, copy);     //new_node:新节点指针

        if (new_node == NULL)       // 检查新节点是否建立成功
            return ERROR;       // 若失败，函数在此返回
        
        new_node->next = llist->head->next;
        llist->head->next = new_node;
        llist->length++;
        return SUCCESS;     // 正常 return
    }   // end if 
    return ERROR;
}   // end


/**
 * @description: 在表尾插入元素项 elem
 * @input: 
 * llist：链表指针
 * elem：元素项指针
 * copy：元素项操作函数指针，将一个元素项复制给同型变量
 * @output: 元素项在表尾加入链表
 */
Status AddTail(PtrList const llist, const DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (llist != NULL) {

        PtrNode tail = FindIndex(llist, llist->length);         // tail：表尾指针
        PtrNode new_node = NewNode(elem, copy);        //new_node:新节点指针

        if (new_node == NULL)       // 检查新节点是否建立成功
            return ERROR;           // 异常，函数在此结束
        
        tail->next = new_node;
        llist->length++;
        return SUCCESS;     // 正常，return
    } // end if
    return ERROR;
}   // end


/**
 * @description: 在位序为 index 的元素后面插入元素项
 * @input: 
 * llist：链表指针
 * elem：元素项指针
 * copy：元素项操作函数指针，将一个元素项复制给同型变量
 * @output: 元素项 elem 插入到 index 节点后面
 */
Status InsertElem(PtrList const llist, const DataType *const elem, int index, void (*copy)(const DataType *const, DataType *const))
{
    if (llist != NULL) {

        PtrNode ptr_insert;     // 指向 index元素项的指针

        if ((ptr_insert = FindIndex(llist, index)) != NULL) {   // 查找index元素项的地址

            PtrNode new_node = NewNode(elem, copy);

            if (new_node != NULL) {

                new_node->next = ptr_insert->next;
                ptr_insert->next = new_node;
                llist->length++;

                return SUCCESS;     // 正常，return
            } // end if
        } // end if
    } // end if
    return ERROR;
} // end


/**
 * @description: 删除位序为 index 的元素项
 * @input: 
 * llist：链表指针
 * index：元素项在表中的位序(不含头节点，1~length)
 * @output: index项元素从表中删除
 */
Status DeleteElem(PtrList const llist, int index)
{
    PtrNode ptr_front;      // 指向 index 元素项的前驱的指针
    PtrNode backup;        // 备份指针

    if (llist != NULL) {

        if (index < 1 || index > llist->length)     // 检查 index 是否合法
            return ERROR;       // 异常，函数在此返回
    
        else {

            if (index == 1)     // 删除链表的头元素
                ptr_front = llist->head;    // 指针指向头节点
            else
                ptr_front = FindIndex(llist, index - 1);    // 指针指向前驱元素
            
            backup = ptr_front->next->next;
            free(ptr_front->next);
            ptr_front->next = backup;
            llist->length--;
            return SUCCESS;     // 正常， return
        }   // end else
    } // end if
    return ERROR;
}


/**
 * @description: 删除整张表
 * @input: 链表指针
 * @output: 链表节点空间全部释放，头指针指向free
 */
Status DeleteList(PtrList const llist)
{
    if (llist != NULL) {

        PtrNode ptr = llist->head, backup;

        while (ptr != NULL) {
            
            backup = ptr->next;
            free(ptr);
            ptr = backup;
        }   // end while
        llist->head = NULL;
        return SUCCESS;
    }   // end if
    return ERROR;
} // end


/**
 * @description: 遍历访问整张表
 * @input: 
 * llist：链表指针
 * visit：对元数项进行访问的函数指针，
 * @output: 遍历整张表
 */
Status TraversalList(const PtrList const llist, void (*visit)(const DataType *const))
{
    if (llist != NULL) {

        PtrNode ptr = llist->head->next;

        while (ptr != NULL) {

            visit(&(ptr->elem));
            ptr = ptr->next;
        } // end while
        return SUCCESS;
    } // end if
    return ERROR;
} // end


/**
 * @description: 获取链表中位序为 index 的元素的值
 * @input: 
 * llist：链表指针
 * elem：变量指针，返回index的值
 * index：元素项在链表中的位序
 * copy：数据项复制函数指针，将一个元素项的值复制到另一变量
 * @output: 
 */
Status GetElem(const PtrList const llist, DataType *elem, int index, void (*copy)(const DataType *const, DataType *const))
{
    if (llist != NULL) {

        if (index >=1 && index <= llist->length) {      // 检查index是否合法

            PtrNode ptr = FindIndex(llist, index);
            CopyData(&(ptr->elem), elem);
            return SUCCESS;     //正常，return
        }   // end if
    }   // end if
    return ERROR;
} // end