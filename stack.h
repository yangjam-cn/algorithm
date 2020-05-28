/*
 * @Author: youngjam
 * @Date: 2020-04-26 20:48:51
 * @LastEditTime: 2020-04-26 21:54:41
 * @Description:栈的基本结构声明和操作定义 
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */

#ifndef STACK_H
#define STACK_H

#include"datatype.h"

typedef enum {ERROR, SUCCESS}Status;

typedef struct StackNode {
    DataType elem;
    struct StackNode *next;
}StackNode, *PtrSNode;

typedef struct Stack {
    PtrSNode top;
    PtrSNode bottom;
    int size;
}Stack, *PtrStack;

/* 初始化栈空间 */
Status InitStack(PtrStack const stack);

/* 元素出栈 */
Status PopStack(PtrStack const stack, DataType *const elem, void (*copy)(const DataType *const, DataType *const));

/* 元素入栈 */
Status PushStack(PtrStack const stack, const DataType *const elem, void (*copy)(const DataType *const, DataType *const));

/* 清零栈空间 */
Status CleanStack(PtrStack const stack);

/* 销毁栈空间 */
void DestoryStack(PtrStack stack);

#endif
