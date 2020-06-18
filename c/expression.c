/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: expression.c
 * @Description: 表达式转换及计算
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-17 19:17:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-18 13:48:48
 */ 
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
#define TRUE    1
#define FALSE   0

typedef char Dtype;
typedef int  Bool;
typedef struct stack
{
    Dtype ele[MAXSIZE];
    int top;
}Stack;
typedef struct queue
{
    Dtype ele[MAXSIZE];
    int front, rear;
}Queue;

/* 栈操作 */

/* 栈是否为空 */
Bool Stack_is_empty(Stack *s)
{
    return s->top == -1;
}

/* 栈是否已满 */
Bool Stack_is_full(Stack *s)
{
    return s->top == (MAXSIZE - 1);
}

/* 入栈 */
void Push(Stack *s, Dtype ele)
{
    if (!Stack_is_full(s))
    {
        s->ele[++(s->top)] = ele;
    }
}

/* 出栈 */
void Pop(Stack *s, Dtype *ele)
{
    if (!Stack_is_empty(s))
    {
        *ele = s->ele[(s->top)--];
    }
}

/* 查看栈顶元素 */
Dtype Get_top(Stack *s)
{
    Dtype top = '0';
    if (!Stack_is_empty(s))
    {
        top = s->ele[s->top];
    }
    return top;
}

/* 队列操作 */

/* 队列是否为空 */
Bool Queue_is_empty(Queue *q)
{
    return q->front == -1;
}

/* 队列是否已满 */
Bool Queue_is_full(Queue *q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}

/* 入队 */
void Enqueue(Queue *q, Dtype ele)
{
    if (!Queue_is_full(q))
    {
        q->rear = (q->rear + 1) % MAXSIZE;
        q->ele[q->rear] = ele;
        if (q->front == -1 && q->rear == 0)
        {
            q->front = 0;
        }
    }
}

/* 出队 */
void Dequeue(Queue *q, Dtype *ele)
{
    if (!Queue_is_empty(q))
    {
        if (q->front == q->rear)
        {
            *ele = q->ele[q->front];
            q->front = q->rear = -1;
        }
        else
        {
            *ele = q->ele[q->front];
            q->front = (q->front + 1) % MAXSIZE;
        }
    }
}

/* 打印队列 */
void Print_queue(Queue *q)
{
    if (!Queue_is_empty(q))
    {
        int cur = q->front;
        while (cur != q->rear)
        {
            printf("%c", q->ele[cur]);
            cur = (cur + 1) % MAXSIZE;
        }
        printf("%c\n", q->ele[cur]);
    }
}

/* 表达式操作 */

/* 获取栈内优先级 */
int Get_isp(Dtype ele)
{
    int isp;
    switch (ele)
    {
        case '*':
        case '/':
        case '%':
            isp = 6;
            break;
        case '+':
        case '-':
            isp = 5;
            break;
        case '(':
        case '#':
            isp = 0;
            break;
    }
    return isp;
}

/* 获取栈外优先级 */
int Get_icp(Dtype ele)
{
    int icp;
    switch (ele)
    {
        case '*':
        case '/':
        case '%':
            icp = 6;
            break;
        case '+':
        case '-':
            icp = 5;
            break;
        case '(':
            icp = 8;
            break;
        case '#':
            icp = 0;
            break;
    }
    return icp;
}

/* 判断是否为操作数 */
Bool Is_operand(Dtype ele)
{
    return ((ele >= '0' && ele <= '9') || (ele >= 'a' && ele <= 'z'));
}

/* 中序转为后序 */
void Infix_to_Postfix(Stack *s, Queue *q, Dtype *ele)
{
    int isp, icp;
    Dtype top = '0';
    Push(s, '#');
    while (*ele != '#')
    {
        /* 当前元素为操作数 */
        if (Is_operand(*ele))
        {
            /* 操作数直接加入队列 */
            Enqueue(q, *ele);
            ele++;
        }    /* end case{ele是操作数}*/

        /* 当前元素为运算符 */
        else if (*ele != ')')
        {
            icp = Get_icp(*ele);    /* 获取栈外优先级 */
            top = Get_top(s);       /* 查看栈顶元素 */
            isp = Get_isp(top);     /* 过去栈顶元素优先级 */
            /* 当栈外优先级小于或等于栈内优先级 */
            while (icp <= isp)
            {
                /* 弹出栈内运算符加入队列 */
                Pop(s, &top);
                Enqueue(q, top);
                /* 更新栈顶元素优先级 */
                top = Get_top(s);
                isp = Get_isp(top);
            }
            /* 栈外优先级高于栈内优先级，压入堆栈 */
            Push(s, *ele);
            ele++;
        }    /* end case{ele是运算符} */

        /* 当前元素为“）” */
        else
        {
            top = Get_top(s);
            /* 弹出栈内元素直到“(” */
            while (top != '(')
            {
                Pop(s, &top);
                if (top != '(')
                {
                    Enqueue(q, top);
                }
            }
            /* 当跳过while时 */
            top = Get_top(s);
            if (top == '(')
            {
                Pop(s, &top);
            }
            ele++;
        }    /* end case{ele是“）”} */
    }    /* end case{ele为表达式序列字符} */

    /* 当前元素为“#” */
    top = Get_top(s);

    /* 弹出栈顶元素直到“#” */
    while (top != '#')
    {
        Pop(s, &top);
        /* “#”不加入队列 */
        if (top != '#')
        {
            Enqueue(q, top);
        }
    }
}

/* 
 * 应该使用联合体构成的堆栈
 */
/*
int Calculate_operator(Dtype op1, Dtype op2, Dtype operator)
{
    int left, right;
    int result = 0;
    if ((op1 >= '0' && op1 <= '9') && (op2 >= '0' && op2 <= '9'))
    {
        left = op2 - '0';
        right = op1 - '0';
    }
    switch (operator)
    {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '%':
            result = left % right;
            break;
    }
    return result;
}

int Calculate_postfix(Stack *s, Queue *q)
{
    int result;
    Dtype ele;
    Dtype op1, op2;
    while (q->front != -1)
    {
        Dequeue(q, &ele);
        if (Is_operand(ele))
        {
            Push(s, ele);
        }
        else
        {
            Pop(s, &op1);
            Pop(s, &op2);
            // result为int型无法压入堆栈
            result = Calculate_operator(op1, op2, ele);
            Push(s, result);
        }
    }
    Pop(s, &result);
    return result;
}
*/


int main()
{
    Stack s = {.top = -1};
    Queue q = {.front = -1, .rear = -1};
    Dtype exp[MAXSIZE], ele;
//    int result = 0;

    printf("input the expression: ");
    scanf("%s", exp);
    Infix_to_Postfix(&s, &q, (Dtype *)exp);
    Print_queue(&q);
 //   result = Calculate_postfix(&s, &q);
    return 0;
}

