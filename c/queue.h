/*
 * @Author: youngjam
 * @Date: 2020-04-27 12:21:58
 * @LastEditTime: 2020-04-27 13:26:02
 * @Description:队列基本结构定义及函数定义 
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */

#include"datatype.h"

typedef enum Status{ERROR, SUCCESS} Status;

/* 定义队列节点结构 */
typedef struct QueueNode {
    DataType elem;
    struct QueueNode *next;
}QueueNode, *PtrQNode;

/* 定义队列结构 */
typedef struct Queue {
    PtrQNode head;      // 队首指针
    PtrQNode tail;        // 队尾指针
    int size;                   // 队列当前大小
}Queue, *PtrQueue;

/* 初始化已存在队列 */
Status InitQueue(PtrQueue const queue);

/* 元素项入队 */
Status Enqueue(PtrQueue const queue, const DataType *const, void (*copy)(const DataType *const, DataType *const));

/* 元素项出队 */
Status Dequeue(PtrQueue const queue, DataType *const, void (*copy)(const DataType *const, DataType *const));

/* 判断队列是否为空 */
int IsEmptyQueue(const PtrQueue const queue);

/* 清零队列 */
Status ClearQueue(PtrQueue const queue);

