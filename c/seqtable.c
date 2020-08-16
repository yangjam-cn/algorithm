/*
 * @Author: youngjam
 * @Date: 2020-04-25 21:47:47
 * @LastEditTime: 2020-04-25 23:56:32
 * @Description: 顺序表的实现
 * @logs: 
    *4.25-->创建文件 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include"seqtable.h"
#include<stdlib.h>
#include<stdio.h>

/**
 * @description: 检查 malloc 函数分配地址是否成功
 * @input:  malloc函数分配的地址
 * @output: 返回是否分配成功标志
 */
Status CheckMalloc(void *ptr)
{
    if (ptr == NULL)
        return ERROR;

    else
        return SUCCESS;
}   //  end


/**
 * @description: 初始化一张顺序表
 * @input: 顺序表的地址
 * @output: 为表的数据域分配存储空间，其表长赋值为 0
 */
Status InitTable(PtrTable table)
{
    if (table != NULL) {

        table->element = (DataType *)malloc(INITSIZE * sizeof(DataType));

        if (CheckMalloc(table->element)) {      //检查 malloc 函数分配地址是否成功
            
            table->length = 0;
            return SUCCESS;
        }   // end if
        else
            return ERROR; 
    }   // end if
    else
        return ERROR;
}   // end


/**
 * @description: 向顺序表的表尾添加元素项
 * @input: 
 * table：顺序表表指针
 * elemenr：待添加元素项的指针
 * copy：数据类型操作函数
 * @output: 元素项被成功添加到表尾，否则返回 ERROR 标志
 */
Status AddElem(PtrTable table, const DataType *element, void (*copy)(DataType const *const, DataType *const))
{
    if (table != NULL) {    // 检查表指针是否合法

        if (table->length < INITSIZE) {     // 检查表是否已满

            (*copy)(element, table->element + table->length);
            table->length++;

            return SUCCESS;       
        }   // end if

        else {
            printf("\ntable is full!\n");
            return ERROR;
        } // end else
    }   // end
    return ERROR;
}   // end


/**
 * @description: 删除自然位序为 index 的元素项
 * @input: 
 * table：顺序表指针
 * index：元素项在表中的自然位序（1~length）
 * copy：数据项操作函数
 * @output: 成功删除位序为 index 的元素项，并将其后元素项前移；否则返回ERROR
 */
Status DeleteElem(PtrTable table, int index, void (*copy)(DataType const *const, DataType *const))
{
    if (table != NULL) {

        if (index > 0 && index <= table->length) {      // 检查位序是否合法

            int i = index - 1;      // 元素项在表中的下标，比自然次序小 1

            while (i < table->length - 1) {     // 遍历 index 之后的元素，并前移一位

                (*copy)(table->element + (i + 1), table->element + i);
                i++;
            }   // end while
            table->length--;        // 删除成功后，表长减 1 
            return SUCCESS;
        }   // end if

        else {      // 当位序超出范围时，输出提示信息，并返回ERROR
            printf("\nindex is out of range!\n");
            return ERROR;
        }   // end else
    }   // end if
    return ERROR;
}   // end


/**
 * @description: 删除表中的元素项
 * @input: 表指针
 * @output: 释放表的数据域指针，并置NULL
 */
Status DeleteTable(PtrTable table)
{
    if (table != NULL) {

        free(table->element);
        table->element = NULL;
        return SUCCESS;
    } // end if
    return ERROR;
}   // end


/**
 * @description: 返回表的长度
 * @input: 表指针
 * @output: 表的长度
 */
int TableLength(PtrTable table)
{
    if (table != NULL)
        return table->length;
    return 0;
} // end


/**
 * @description: 遍历表中的所有元素
 * @input: 
 * table：表指针
 * visit：数据项操作函数
 * @output: 表中所有元素项访问一边
 */
Status TraversalTable(PtrTable table, void (*visit)(DataType const *const))
{
    if (table != NULL) {

        for (int i = 0; i < table->length; i++) {

            (*visit)(table->element + i);   
        } // end for
        return SUCCESS;
    }   // end if
    return ERROR;
}   // end