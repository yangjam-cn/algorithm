/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: linked_queue.c
 * @Description: 链式队列的实现
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-17 08:36:57
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-17 10:27:14
 */ 
#include<stdio.h>
#include<stdlib.h>

#define TRUE  1
#define FALSE 0

typedef int Bool;
typedef char Dtype;
/* 队列结点结构定义 */
typedef struct linked_queue_node
{
    Dtype ele;    /* 数据域 */
    struct linked_queue_node *next;    /* 链接域 */
}LQ_node;
typedef LQ_node *Ptr_Node;    /* 结点指针类型定义 */
/* 队列结构定义 */
typedef struct linked_queue
{
    Ptr_Node front, rear;    /* 头指针，尾指针 */
}LQueue;
typedef LQueue *Ptr_Queue;    /* 队列指针类型定义 */

/*++++++ 运算定义 ++++++*/

/* 创建队列 */
Ptr_Queue Create_queue();

/* 元素入队 */
void Enqueue(Ptr_Queue const lqueue, Dtype ele);

/* 元素出队 */
void Dequeue(Ptr_Queue const lqueue, Dtype *ele);

/* 销毁队列 */
Ptr_Queue Destory_queue(Ptr_Queue lqueue);

/* 检查队列是否为空 */
Bool Is_empty(Ptr_Queue const lqueue);

/* 获取队首元素 */
Dtype Get_front(Ptr_Queue const lqueue);


/******* 运算实现 *******/

/* 检查malloc()分配内存是否成功 */
static inline Bool Malloc_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        puts("memory allocation failure!");
        return TRUE;
    }
    return FALSE;
}

/* 检查队列指针是否为null */
static inline Bool Is_nullptr(Ptr_Queue lq)
{
    if (lq == NULL)
    {
        puts("linked queue pointer is null!");
        return TRUE;
    }
    return FALSE;
}


/* 创建新结点 */
static Ptr_Node Create_Node(Dtype ele)
{
    Ptr_Node new_node = (Ptr_Node)malloc(sizeof(LQ_node));
    if (!Malloc_is_null(new_node))
    {
        new_node->ele = ele;
        new_node->next = NULL;
    }
    return new_node;
}

Bool Is_empty(Ptr_Queue lq)
{
    return lq->front == NULL;
}

Ptr_Queue Create_queue(void)
{
    Ptr_Queue lq = (Ptr_Queue)malloc(sizeof(LQueue));
    if (!Malloc_is_null(lq))
    {
        lq->front = lq->rear = NULL;
    }
    return lq;
}

void Enqueue(Ptr_Queue lq, Dtype ele)
{
    if (!Is_nullptr(lq))
    {
        Ptr_Node new_node = Create_Node(ele);

        if (Is_empty(lq))
        {
            lq->front = lq->rear = new_node;
        }
        else
        {
            /* 
             * 注意此处与栈的区别
             * 栈是先入后出，链是从后往前指
             * 队列是先入先出，链是从前往后指
             */
            lq->rear->next = new_node;
            lq->rear = new_node;
        }
    }
}

void Dequeue(Ptr_Queue lq, Dtype *ele)
{
    if (!Is_nullptr(lq))
    {
        if (!Is_empty(lq))
        {
            /* 
             * 队列仅有唯一元素，出队后指针指向NULL
             * front和rear为不同变量，若仅使用else中代码，则最后元素出队后，rear仍指向该结点
             */
            if (lq->rear == lq->front)
            {
                *ele = lq->front->ele;
                free(lq->front);
                lq->front = lq->rear = NULL;
            }
            else
            {
                *ele = lq->front->ele;
                Ptr_Node tmp = lq->front;
                lq->front = tmp->next;
                free(tmp);
                /*
                 if (lq->front == NULL) 
                     lq->rear = NULL;
                */
            }
        }
        else
        {
            puts("the queue is empty!");
        }
        
    }
}

Ptr_Queue Destory_queue(Ptr_Queue lq)
{
    if (!Is_nullptr(lq))
    {
        if (!Is_empty(lq))
        {
            Ptr_Node tmp = lq->front;

            while (lq->front != NULL)
            {
                tmp = lq->front->next;
                free(lq->front);
                lq->front = tmp;
            }
            lq->rear = NULL;
        }
        lq = NULL;
    }
    return lq;
}

Dtype Get_front(Ptr_Queue lq)
{
    Dtype ele = '0';
    if (!Is_nullptr(lq))
    {
        if (!Is_empty(lq))
        {
            ele = lq->front->ele;
        }
    }
    return ele;
}


/* test */

int main(void)
{
    char flag = '0';
    Dtype ele;
    Ptr_Queue lq = Create_queue();
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch (flag)
        {
            case '1':
                printf("input the ele: ");
                getchar();
                scanf("%c", &ele);
                Enqueue(lq, ele);
                break;
            case '2':
                Dequeue(lq, &ele);
                printf("the ele of dequeue: %c\n", ele);
                break;
            case '3':
                ele = Get_front(lq);
                printf("the front ele is: %c\n", ele);
                break;
            default:
                break;
        }
    }
    lq = Destory_queue(lq);
    printf("%p", lq);
    return 0;
}
