/* 
 *2020年 04月 16日 星期四 15:17:22 CST
 *基于数组的堆栈实现
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define max_length 100
typedef struct Stack {
    int data[max_length];
    int top;
}stack;

int is_empty(stack const * const s)
{
    return s->top == -1 ;
}

void push(stack *const s, int data)
{
    if (s->top >= (max_length - 1)) {
        printf("stack is full!\n");
        return;
    }
    else {
        s->top++;
        s->data[s->top] = data;
    }
}

void pop(stack *s)
{
    if (is_empty(s)) {
        printf("stack is empty!\n");
        return;
    }
    else {
        printf("the top element is %d\n", s->data[s->top--]);
    }
}

int main(void)
{
    stack s;
    s.top = -1;
    srand((int)time(0));
    int flag = 1;
    int value = 0;
    while (flag != -1) {
        value = rand() % 30;
        printf("rand = %d\n", value);
        printf("push: input 1; pop: input 0; exit: input -1:   ");
        scanf("%d", &flag);
        if (flag == 1)
            push(&s, value);
        else if (flag == 0)
            pop(&s);
    }
    printf("============\n");
    for (int i = s.top; i >= 0; i--)
        pop(&s);
}