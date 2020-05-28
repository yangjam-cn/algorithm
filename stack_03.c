/*
 *2020年 04月 16日 星期四 21:02:55 CST
 *基于链表实现的栈
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct StackNode *stack_ptr;
typedef struct StackNode {
    int data;
    stack_ptr next;
}stack_node;

int is_empty(stack_ptr stack_top)
{
    return stack_top == NULL;
}

void push(stack_ptr *stack_top, int data)
{
    stack_ptr new_node = (stack_ptr)malloc(sizeof(stack_node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = *stack_top;
        *stack_top = new_node;
    }
    else {
        printf("memory allocation failure!\n");
        exit(-1);
    }
}

int pop(stack_ptr *stack_top)
{
    if (is_empty(*stack_top)) {
        printf("stack is empty!");
        return -1;
    }
    else{
        stack_ptr temp = *stack_top;
        *stack_top = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

int main(void){
    srand((int)time(0));
    int flag = 1, value;
    stack_ptr stack_top = NULL;
    while (flag != -1) {
        printf("pop = 0; push = 1; exit = -1:   ");
        scanf("%d", &flag);
        if (flag == 1){
            value = rand() % 20;
            printf("rand = %d\n", value);
            push(&stack_top, value);
        }
        else if (flag == 0) {
            printf("the top data :\t%d\n", pop(&stack_top));
        }
    }
    printf("++++++++++++\n");
    while (!is_empty(stack_top)) {
        printf("the top data:\t%d\n", pop(&stack_top));
    }
    return 0;
}