/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: seq_circular_queue.c
 * @Description: 顺序循环队列的实现
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-16 14:55:31
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-16 16:19:40
 */ 
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef int Bool;
typedef char Dtype;
/* 顺序循环队列结构定义 */
typedef struct sequential_circular_queue
{
   Dtype element[MAXSIZE];
   int front, rear, size; 
}SCQueue;

/* 运算定义 */

/* 初始化队列 */
void Init_SCQueue(SCQueue *queue, int size);

/* 元素入队 */
void Enqueue(SCQueue *queue, Dtype ele);

/* 元素离队 */
void Dequeue(SCQueue *queue, Dtype *ele);

/* 检查队列是否为空 */
Bool Queue_is_full(SCQueue *queue);

/* 检查队列是否已满 */
Bool Queue_is_empty(SCQueue *queue);

/* 运算实现 */

Bool Queue_is_empty(SCQueue *queue)
{
    /* 
     * 用-1标识队列为空
     * 当最后一个元素离队后，front = (rear + 1) % size，与full判断条件相同
     */
    return queue->rear == -1;
}

Bool Queue_is_full(SCQueue *queue)
{
    /*
     * 当rear从后靠近front时，表明元素入队，队列已满
     * 保证入队操作不可能令rear=front
     */
    return (queue->rear + 1) % queue->size == queue->front;
}


void Init_SCQueue(SCQueue *queue, int size)
{
    queue->size = size;
    queue->front = queue->rear = -1;    /* 当对列游标为-1时表明队列为空 */
}

void Enqueue(SCQueue *queue, Dtype ele)
{
    if (!Queue_is_full(queue))
    {
        /*
         * 当队列为空时，元素入队，首尾游标从0开始移动
         */
        if (Queue_is_empty(queue))
        {
            queue->front = queue->rear = 0;
            queue->element[queue->rear] = ele;
        }
        else
        {
            queue->rear = (queue->rear + 1) % queue->size;
            queue->element[queue->rear] = ele;
        }
    }
    else
    {
        puts("queun is full!");
    }
    
}

void Dequeue(SCQueue *queue, Dtype *ele)
{
    if (!Queue_is_empty(queue))
    {
        /*
         * 当且仅当front=rear时，队列仅剩唯一元素
         * 元素出队，游标指向-1，表明队列已空
         */
        if (queue->front == queue->rear)
        {
            *ele = queue->element[queue->front];
            queue->front = queue->rear = -1; 
        }
        else
        {
            *ele = queue->element[queue->front];
            queue->front = (queue->front + 1) % queue->size;
        }
    }
    else
    {
        puts("queue is empty!");
    }
}

/* 测试 */

int main()
{
    char flag = '0';
    Dtype ele;
    int size, cnt;
    SCQueue queue, *pq;
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch (flag)
        {
            case '1':
                printf("input the size of queue: ");
                scanf("%d", &size);
                Init_SCQueue(pq, size);
                break;
            case '2':
                printf("input the ele that you want enqueue: ");
                getchar();
                scanf("%c", &ele);
                Enqueue(pq, ele);
                break;
            case '3':
                Dequeue(pq, &ele);
                printf("the ele of dequeue: %c\n", ele);
                break;
            case '4':
                cnt = pq->front;
                while (cnt != pq->rear)
                {
                    printf("%c", pq->element[cnt]);
                    cnt = (cnt + 1) % pq->size;
                }
                printf("%c\n", pq->element[cnt]);    /* 存在越界访问的风险 */
                break;
            default:
                break;
        }
    }
    return 0;
}