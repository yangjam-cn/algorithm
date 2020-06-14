/*
 * @Copyright: github.com/yangjam-cn/algorithm
 * @File name: dcll.c
 * @Description: 带头结点的双向循环链表实现
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-06-14 19:13:43
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-14 21:37:17
 */ 
#include<stdio.h>
#include<stdlib.h>

#define true  1
#define false 0

typedef int dtype;
typedef struct doubly_circular_linked_list_node dcll_node;
typedef struct doubly_circular_linked_list_node *ptr_dcll;
struct doubly_circular_linked_list_node
{
    dtype element;
    ptr_dcll last;
    ptr_dcll next;
};

/* 运算定义 */

/* 创建链表头 */
ptr_dcll create_dcll(void);

/* 插入新结点 */
void insert_node(ptr_dcll const header, int location);

/* 删除结点 */
void delete_node(ptr_dcll const header, int location);

/* 查找结点 */
int find_node(ptr_dcll const header, dtype element);

/* 遍历链表 */
void traverse_dcll(ptr_dcll const header);

/* 清除链表 */
ptr_dcll clean_dcll(ptr_dcll header);

/* 运算实现 */

/* 检查malloc()内存分配是否成功 */
static inline int malloc_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        puts("memory allocation failure!");
        return true;
    }
    return false;
}

/* 检查链表头是否为NULL */
static inline int header_is_null(ptr_dcll ptr)
{
    if (ptr == NULL)
    {
        puts("list is NULL!");
        return true;
    }
    return false;
}

/* 检查location是否合法 */
static inline int location_is_valid(ptr_dcll const header, int loc)
{
    if (loc < 0 || loc > header->element)
    {
        puts("location is invalid!");
        return false;
    }
    return true;
}

/* 创建新结点 */
static ptr_dcll create_node(void)
{
    ptr_dcll new_node = (ptr_dcll)malloc(sizeof(dcll_node));
    if (!malloc_is_null(new_node))
    {
        new_node->last = NULL;
        new_node->next = NULL;
        printf("input the value of element: ");
        scanf("%d", &(new_node->element));
    }
    return new_node;
}

/* 
 * 返回链表序号为loc的结点地址 
 * 检查header和loc合法后调用该函数
 */
static ptr_dcll return_address(ptr_dcll const header, int loc)
{
    ptr_dcll ptr_cur = header;
    int cnt = 0;
    while (cnt < loc)
    {
        cnt++;
        ptr_cur = ptr_cur->next;
    }
    return ptr_cur;
}

ptr_dcll create_dcll(void)
{
    ptr_dcll header = (ptr_dcll)malloc(sizeof(dcll_node));
    if (!malloc_is_null(header))
    {
        /* 初始化时，头结点自成环 */
        header->next = header;
        header->last = header;
        header->element = 0;    /* 头结点保存链表长度信息 */
    }
    return header;
}

void insert_node(ptr_dcll const header, int location)
{
    if (!header_is_null(header))
    {
        if (location_is_valid(header, location))
        {

            ptr_dcll new_node = create_node();
            ptr_dcll loc = return_address(header, location);
            /* 
             * s1.将新结点加入链表
             * s2.更新原有链接信息
             */
            new_node->next = loc->next;
            new_node->last = loc;
            loc->next = new_node;
            new_node->next->last = new_node;
            header->element++;    /* 链表长度加1 */
        }
    }
}

void delete_node(ptr_dcll const header, int location)
{
    if (!header_is_null(header))
    {
        if (location_is_valid(header, location - 1))
        {
            ptr_dcll loc = return_address(header, location);
            loc->last->next = loc->next;    /* 更新前驱结点后继 */
            loc->next->last = loc->last;    /* 更新后继结点前驱 */
            free(loc);    /*** 释放已删除结点的内存 ***/
            header->element--;    /* 链表长度减1 */
        }
    }
}

int find_node(ptr_dcll const header, dtype element)
{
    if (!header_is_null(header))
    {
        int cnt = 1;
        ptr_dcll ptr_cur = header->next;
        while (ptr_cur->element != element && ptr_cur != header)
        {
            ptr_cur = ptr_cur->next;
            cnt++;
        }
        if (ptr_cur == header)    /* 指针移动到头指针，表明链表中无该元素 */
        {
            puts("elemnet isn't in the list!");
            cnt = -1;
        }
        return cnt;
    }
    return -1;
}

void traverse_dcll(ptr_dcll const header)
{
    if (!header_is_null(header))
    {
        ptr_dcll ptr_cur = header->next;
        while (ptr_cur != header)
        {
            printf("value of this node: %d\n", ptr_cur->element);
            ptr_cur = ptr_cur->next;
        }
    }
}

ptr_dcll clean_dcll(ptr_dcll header)
{
    if (!header_is_null(header))
    {
        ptr_dcll ptr_cur = header->next;   /* 从头结点后继开始遍历 */
        while (ptr_cur != header)
        {
            ptr_cur = ptr_cur->next;
            free(ptr_cur->last);
        }
        free(ptr_cur);    /* 释放头结点空间 */
        header = NULL;    /* 头结点指向NULL，防止错误访问 */
    }
    return header;
}

/* 测试 */

int main()
{
    char flag = '0';
    int loc;
    dtype ele;
    ptr_dcll header = create_dcll();
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch(flag)
        {
            case '1':
                printf("input the loc that you want insert: ");
                scanf("%d", &loc);
                insert_node(header, loc);
                break;
            case '2':
                printf("input the loc that you wnat delete: ");
                scanf("%d", &loc);
                delete_node(header, loc);
                break;
            case '3':
                printf("input the ele that you want find: ");
                scanf("%d", &ele);
                loc = find_node(header, ele);
                printf("loc = %d\n", loc);
                break;
            case '4':
                traverse_dcll(header);
                break;
            default:
               break;
        }
    }
    header = clean_dcll(header);
    printf("%p\n", header);
    return 0;
}

