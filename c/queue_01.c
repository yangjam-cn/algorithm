/*
 * @Author: youngjam
 * @Date: 2020-04-23 15:51:28
 * @LastEditTime: 2020-04-23 17:03:35
 * @Description: 基于数组的队列实现
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

typedef struct Queue {
    int data[MAXSIZE];
    int front;
    int rear;
}IntQueue;

/* 初始化队列的首尾游标 */
void InitQueue(IntQueue *p_queue)
{
    p_queue->front  = -1;
    p_queue->rear   = -1;
}   // end InitQueue

/* 将data从队尾加入队列 */
void Enqueue(IntQueue *p_queue, int data)
{
    if (p_queue->rear >= MAXSIZE - 1) {
        printf("queue is full!\n");
    }   // end if

    else {
        p_queue->rear++;
        p_queue->data[p_queue->rear] = data;
    }   // end else
}   // end Enqueue

/* 对首元素离开队列，并返回函数调用处 */
int Dequeue(IntQueue *p_queue)
{
    if (p_queue->front >= p_queue->rear) {
        printf("queue is empty!\n");
        return -1;
    }   // end if

    else {
        p_queue->front++;
        return p_queue->data[p_queue->front];
    }   // end else
}   // end Dequeue

int main(void)
{
    srand((int)time(NULL));

    IntQueue i_queue;       // 声明存放 int 类型队列

    InitQueue(&i_queue);

    char flag = 'e';

    while (flag != 'q') {

        int data = 0;

        printf("[e] => enqueue();  [d] => dequeue();  [q] => quit!\t");
        // flag = getchar();    /*==> error: 输出语句的'\n'会留在缓冲区赋给flag <==*/
        while ((flag = getchar()) == '\n');     // 消耗掉缓冲区 '\n' 
       
        switch (flag) {

            case 'e':
                data = rand() % 20;
                printf("value = %d\n", data);
                Enqueue(&i_queue, data);
                break;

            case 'd':
                data = Dequeue(&i_queue);
                printf("the value of left is: %d\n", data);
                break;

            default:
                break;
        }   // end switch
    }   // end while

    while (i_queue.rear > i_queue.front) {
        printf("the value of dequeue:\t%d\n", Dequeue(&i_queue));
    }   // end while
    
    return 0;
}   // end main()
