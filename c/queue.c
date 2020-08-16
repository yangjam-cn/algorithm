/*
 * @Author: youngjam
 * @Date: 2020-04-27 12:54:28
 * @LastEditTime: 2020-04-27 14:00:55
 * @Description: 队列基本实现
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"queue.h"

#define false 0
#define true  1


/**
 * @description: 检查malloc函数分配地址是否成功
 * @input: malloc函数分配地址 
 * @output: 是否分配成功，若分配地址为空，输出提示信息
 */
Status CheckMalloc(void *ptr)
{
    if (ptr == NULL) {

        printf("memory allocation failure!\n");
        return ERROR;
    }   // end if
    return SUCCESS;
} // end


/**
 * @description: 初始化队列
 * @input: 队列指针
 * @output: 队首和队尾指针初始化为null，队列大小初始化为0
 */
Status InitQueue(PtrQueue const queue)
{
    if (queue != NULL) {

        queue->head = queue->tail = NULL;
        queue->size = 0;
        return SUCCESS;     // 正常，return
    }
    return ERROR;   
} // end


/**
 * @description: 元素入队
 * @input: 
 * queue：队列指针
 * elem：待加入队列的元素的指针
 * copy：数据项操作函数指针，将一个数据项复制给另一个
 * @output: 元素项加入到队尾，更新队尾指针
 */
Status Enqueue(PtrQueue const queue, const DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (queue != NULL) {

        PtrQNode new_node = (PtrQNode)malloc(sizeof(QueueNode));

        if (CheckMalloc(new_node)) {

            (*copy)(elem, &(new_node->elem));
            new_node->next = NULL;

            if (IsEmptyQueue(queue)) {      // 队列为空，将新节点设为队首
                queue->head = new_node;
            } // end if
            else {      // 队列非空，链到队尾
                queue->tail->next = new_node;
            } // end else
            queue->tail = new_node;
            queue->size++;
            
            return SUCCESS;     // 正常，return
        } // end if
    } // end if
    return ERROR;
} // end


/**
 * @description: 元素项离开队列
 * @input: 
 * queue：队列指针
 * elem：通过elem将对首元素项返回调用处
 * copy：数据项操作函数指针，将一个数据项复制给另一个同型数据项
 * @output: 元素离开队列，更新队首指针
 */
Status Dequeue(PtrQueue const queue, DataType *const elem, void (*copy)(const DataType *const, DataType *const))
{
    if (queue != NULL) {

        if (!IsEmptyQueue(queue)) {  // 队列非空

            (*copy)(&(queue->head->elem), elem);

            if (queue->head == queue->tail && queue->size == 1) { // 队列仅剩唯一元素

                free(queue->head);
                queue->tail =queue->head = NULL;
            }   // end if

            else {  // 一般情况处理

                PtrQNode backup = queue->head->next;
                free(queue->head);
                queue->head = backup;
            }   // end else
            
            queue->size--;

            return SUCCESS;     // 
        } // end if
    } // end if
    return ERROR;
} // end


/**
 * @description: 检查队列是否为空
 * @input: 队列指针
 * @output: 若队列为空，返回true；否则返回false
 */
int IsEmptyQueue(const PtrQueue const queue)
{
    if (queue->size == 0 && (queue->tail == NULL && queue->head == NULL))
        return true;
    else
        return false;
} // end


/**
 * @description: 清零队列
 * @input: 队列指针
 * @output: 释放队列空间的所有节点
 */
Status ClearQueue(PtrQueue const queue)
{
    if (queue != NULL) {

        PtrQNode ptr = queue->head, backup;

        while (ptr != NULL) {
            backup = ptr->next;
            free(ptr);
            ptr = backup;
        } // end while
        queue->size = 0;
        queue->tail = queue->head = NULL;
        return SUCCESS;
    }
    return ERROR;
} // end