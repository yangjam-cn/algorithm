/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: linked_stack.c
 * @Description: 链式栈的实现
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-16 08:30:41
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-16 10:39:56
 */ 
#include<stdio.h>
#include<stdlib.h>

#define false 0
#define true  1

typedef int bool;
typedef char dtype;
/* 栈结点结构体定义 */
typedef struct linked_stack_node
{
    dtype m_ele;                          /* 数据域 */
    struct linked_stack_node *mp_next;    /* 链接域 */
}ls_node;
typedef ls_node *sp_node;    /* 栈结点指针类型定义 */
/* 栈结构体定义 */
typedef struct linked_stack
{
    sp_node mp_top;    /* 栈顶指针 */
    int size;          /* 当前栈大小 */
}linked_stack;
typedef linked_stack *sp_stack;    /* 栈指针类型定义 */

/* 运算 */

/* 创建链式栈 */
sp_stack create_ls(void);

/* 元素入栈 */
void push_ls(sp_stack ls, dtype ele);

/* 元素出栈 */
void pop_ls(sp_stack ls, dtype *ele);

/* 获取栈顶元素 */
dtype get_top_ls(sp_stack ls);

/* 销毁栈空间 */
sp_stack destory_ls(sp_stack ls);


/* 运算实现 */

/* 检查malloc()地址是否分配成功 */
static inline bool malloc_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        puts("memory allocation filure!");
        return true;
    }
    return false;
}

/* 检查栈是否为空 */
static inline bool ls_is_empty(sp_stack ls)
{
    if (ls->size == 0 || ls->mp_top == NULL)
    {
        puts("linked stack is empty!");
        return true;
    }
    return false;
}

/* 检查栈指针是否为空 */
static inline bool sp_is_null(sp_stack ls)
{
    if (ls == NULL)
    {
        puts("linked stack pointer is null!");
        return true;
    }
    return false;
}

/* 创建新结点 */
static sp_node create_node(dtype ele)
{
    sp_node new_node = (sp_node)malloc(sizeof(ls_node));
    if (!malloc_is_null(new_node))
    {
        new_node->m_ele = ele;
        new_node->mp_next = NULL;
    }
    return new_node;
}

sp_stack create_ls(void)
{
    sp_stack ls = (sp_stack)malloc(sizeof(linked_stack));
    if (!malloc_is_null(ls))
    {
        ls->mp_top = NULL;
        ls->size = 0;
    }
    return ls;
}

void push_ls(sp_stack ls, dtype ele)
{
    if (!sp_is_null(ls))
    {
        sp_node new_node = create_node(ele);

        new_node->mp_next = ls->mp_top;
        ls->mp_top = new_node;
        ls->size++;
    }
}

void pop_ls(sp_stack ls, dtype *ele)
{
    if (!sp_is_null(ls))
    {
        if (!ls_is_empty(ls))
        {
            *ele = ls->mp_top->m_ele;
            sp_node tmp = ls->mp_top;
            ls->mp_top = ls->mp_top->mp_next;
            free(tmp);
            ls->size--;
        }
    }
}

dtype get_top_ls(sp_stack ls)
{
    dtype ele = ' ';
    if (!sp_is_null(ls))
    {
        if (!ls_is_empty(ls))
        {
            ele = ls->mp_top->m_ele;
        }
    }
    return ele;
}

sp_stack destory_ls(sp_stack ls)
{
    if (!sp_is_null(ls))
    {
        if (!ls_is_empty(ls))
        {
            sp_node tmp = ls->mp_top;
            while (tmp != NULL)
            {
                ls->mp_top = tmp->mp_next;
                free(tmp);
                tmp = ls->mp_top;
            }
        }
        free(ls);
        ls = NULL;
    }
    return ls;
}

/* 测试 */

int main(void)
{
    char flag = '0';
    dtype ele;
    sp_stack ls = create_ls();
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch(flag)
        {
            case '1':
                printf("input the ele that you want push: ");
                getchar();
                scanf("%c", &ele);
                push_ls(ls, ele);
                break;
            case '2':
                pop_ls(ls, &ele);
                printf("the ele that pop: %c\n", ele);
                break;
            case '3':
                ele = get_top_ls(ls);
                printf("the top ele: %c\n", ele);
                break;
            default:
                break;
        }
    }
    ls = destory_ls(ls);
    printf("%p", ls);
    return 0;
}

