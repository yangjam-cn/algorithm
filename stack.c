/*
 * @Author: youngjam
 * @Date: 2020-04-26 21:12:08
 * @LastEditTime: 2020-04-26 22:19:44
 * @Description: 栈的基本实现
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include "stack.h"
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

#define true 1

/**
 * @description: 检查栈是否为空
 * @input: 栈指针
 * @output: 若栈为空或空指针，返回 true; 否则返回 0(false)
 */
int IsEmpty(PtrStack const stack)
{
    if (stack == NULL)
        return true;
    else
        return stack->top == stack->bottom;
} // end


/**
 * @description: 检查 malloc 函数分配地址是否成功
 * @input: 变量指针
 * @output: 若 ptr 非空，返回 SUCCESS，否则输出分配失败的信息和返回 ERROR
 */
Status CheckMalloc(void *ptr)
{
    if (ptr == NULL) {

        printf("memory allocation failure!\n");
        return ERROR;
    } // end if
    return SUCCESS;
} // end 


/**
 * @description: 初始化已存在的栈空间
 * @input: 栈指针
 * @output: 生成一个空节点，让栈顶和栈底指向该节点，栈大小初始化为 0
 */
Status InitStack(PtrStack const stack)
{
    if (stack != NULL) {

        PtrSNode node = (PtrSNode)malloc(sizeof(StackNode));

        if (CheckMalloc(node)) {    //  检查地址是否分配成功
            
            node->next = NULL;
            stack->bottom = stack->top = node;
            stack->size = 0;

            return SUCCESS;     // 正常，return
        } // end if
    } // end if
    return ERROR;
} // end


/**
 * @description: 弹出栈顶元素
 * @input: 
 * stack：栈指针
 * elem：用于存放返回数据项的指针
 * copy：用于复制数据项的函数指针，将一个数据项复制给另一数据项
 * @output: 弹出栈顶元素，栈顶指针指向下一层节点
 */
Status PopStack(PtrStack const stack, DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (!IsEmpty(stack)) {      // 检查栈是否为空

        (*copy)(&(stack->top->elem), elem);
        PtrSNode backup = stack->top;
        stack->top = stack->top->next;
        free(backup);
        stack->size--;

        return SUCCESS;     // 正常，return
    } // end if
    return ERROR;
} // end


/**
 * @description: 将已存在元素项压入栈
 * @input: 
 * stack：栈指针
 * elem：待压入元素项的指针
 * copy：用于复制数据项的函数指针，将一个数据项复制给另一数据项
 * @output: 元素项压入栈，栈顶指针指向新节点
 */
Status PushStack(PtrStack const stack, const DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (stack != NULL) {

        PtrSNode new_node = (PtrSNode)malloc(sizeof(StackNode));

        if (CheckMalloc(new_node)) {    // 检查新节点是否合法

            (*copy)(elem, &(new_node->elem));
            new_node->next = stack->top;
            stack->top = new_node;
            stack->size++;

            return SUCCESS;
        } // end if
    }   // end if
    return ERROR;
} // end


/**
 * @description: 清零栈空间，释放所有元素项
 * @input: 栈指针
 * @output: 存放元素项的空间被释放，栈顶和栈底都指向底层空节点
 */
Status CleanStack(PtrStack const stack)
{
    if (stack != NULL) {

        PtrSNode ptr = stack->top, backup;

        while (ptr != stack->bottom) {
            
            backup = ptr->next;
            free(ptr);
            ptr = backup;
        } // end while

        stack->top = stack->bottom;
        stack->size = 0;
        return SUCCESS;     // 正常，return
    } // end if
    return ERROR;
} // end


/**
 * @description: 销毁栈空间
 * @input: 栈指针
 * @output: 释放栈指针及其底层空节点
 */
void DestoryStack(PtrStack stack)
{
    if (stack != NULL) {

        if (!IsEmpty(stack)) 
           CleanStack(stack);
        
        free(stack->bottom);
        free(stack);
    } // end if
} // end