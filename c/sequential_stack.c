/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: sequential_stack.c
 * @Description: 顺序栈的实现
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-15 20:03:29
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-15 21:03:48
 */ 
#include<stdio.h>
#include<stdlib.h>

#define max_length 50
#define true       1
#define false      0

typedef int bool;
typedef char dtype;
typedef struct sequential_stack
{
    int top, max_size;    /* top为栈顶指针，max_size为创建栈的最大可用空间 */
    dtype element[max_length];
}seq_stack;

/******* 运算定义 *******/

/* 创建大小为size的顺序栈 */
void create_seq_stack(seq_stack *const ptr_stack, int size);

/* 检查栈是否为空 */
bool stack_is_empty(const seq_stack *const ptr_stack);

/* 检查栈是否已满 */
bool stack_is_full(const seq_stack *const ptr_stack);

/* 元素入栈 */
void push_seq_stack(seq_stack *const ptr_stack, dtype ele);

/* 元素出栈 */
void pop_seq_stack(seq_stack *const ptr_stack);

/* 获取栈顶元素 */
void get_top_seq_stack(seq_stack *const ptr_stack, dtype *const ele);

/******* 运算实现 *******/

void create_seq_stack(seq_stack *const p_stack, int size)
{
    p_stack->top = -1;
    p_stack->max_size = size;
}

bool stack_is_empty(const seq_stack *const p_stack)
{
    return p_stack->top < 0;
}

bool stack_is_full(const seq_stack *const p_stack)
{
    return p_stack->top >= p_stack->max_size - 1;
}

void push_seq_stack(seq_stack *const p_stack, dtype ele)
{
    if (!stack_is_full(p_stack))
    {
        p_stack->top++;
        p_stack->element[p_stack->top] = ele;
    }
    else
    {
        printf("stack is full!\n");
    }
}

void pop_seq_stack(seq_stack *const p_stack)
{
    if (!stack_is_empty(p_stack))
    {
        p_stack->top--;
    }
    else
    {
        printf("stack is empty!\n");
    }
}

void get_top_seq_stack(seq_stack *const p_stack, dtype *const ele)
{
    if (!stack_is_empty(p_stack))
    {
        *ele = p_stack->element[p_stack->top];
    }
    else
    {
        printf("stack is empty!\n");
    }
    
}

/* 测试 */

int main(void)
{
    seq_stack sstack;
    dtype ele;
    char flag = '0';
    printf("%p\n", &ele);
    create_seq_stack(&sstack, 20);
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch(flag)
        {
            case '1':
                printf("input the char that you want input: ");
                getchar();
                scanf("%c", &ele);
                push_seq_stack(&sstack, ele);
                break;
            case '2':
                get_top_seq_stack(&sstack, &ele);
                printf("the top ele is: %c\n", ele);
                break;
            case '3':
                pop_seq_stack(&sstack);
                break;
            default:
                break;
        }
    }
    return 0;
}
