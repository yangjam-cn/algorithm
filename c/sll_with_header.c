/*
 * @Copyright: 
 * @File name: sll_with_header.c
 * @Description: 带头结点的单链表实现
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-06-14 15:17:41
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-14 17:16:12
 */ 
#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0


/******* 数据类型定义 *******/
typedef int dtype;    /* 数据域类型 */
typedef struct singly_linked_list_node sll_node;    /* 定义链表结点类型 */
typedef struct singly_linked_list_node *ptr_sll;    /* 定义链表指针类型 */
/* 链表结点定义 */
struct singly_linked_list_node
{
    dtype element;
    ptr_sll next;
};

/******* 运算定义 *******/


// inline int malloc_is_null(void *const ptr);

/*
 * 创建链表
 */
ptr_sll create_sll(void);

/* 
 * 向链表中插入元素
 */
void insert_node(ptr_sll header, int location);

/*
 * 删除结点
 */
void delete_node(ptr_sll header, int location);

/*
 * 寻找结点
 */
int find_node(ptr_sll header, dtype element);

/*
 * 遍历链表
 */
void traverse_sll(const ptr_sll const header);

/*
 * 清除链表
 */
ptr_sll clean_sll(ptr_sll header);

/******* 运算实现 *******/

/*++++++ 内部函数 ++++++*/
/* 检查malloc()内存分配是否成功 */
static inline int malloc_is_null(void *const ptr)
{
    if (ptr == NULL)
    {
        puts("memory allocation failure!");
        return true;
    }    /* end if */
    return false;
}

/* 检查链表头指针是否为空 */
static inline int header_is_null(ptr_sll const ptr)
{
    if (ptr == NULL)
    {
        puts("linked list is null!");
        return true;
    }   /* end if */
    return false;
}

/* 检查结点位置是否合法 */
static inline int location_is_valid(int location, ptr_sll header)
{
    if (location < 0 ||location > header->element)
    {
        puts("location is invaild!");
        return false;
    }    /* end if */
    return true;
}

/* 寻找指定位序结点的地址 */
static ptr_sll return_address(ptr_sll const header, int location)
{
    ptr_sll ptr_cur = header;
    int cnt = 0;

    /*
     * 若location=0，则返回头指针
     * 若location=header->element，则返回sll尾结点指针
     * ptr_cur!=NULL，防止指针越界访问
     */
    for (cnt = 0; cnt < location && ptr_cur != NULL; cnt++)
    {
        ptr_cur = ptr_cur->next;
    }
    return ptr_cur;
}

/* 创建新结点 */
static ptr_sll create_node(void)
{
    ptr_sll new_node = (ptr_sll)malloc(sizeof(sll_node));
    if (!malloc_is_null(new_node))
    {
        new_node->next = NULL;
        printf("input the element: ");
        scanf("%d", &(new_node->element));
    }    /* end if */
    return new_node;
}

/*++++++ 运算实现 ++++++*/

ptr_sll create_sll(void)
{
    ptr_sll header = (ptr_sll)malloc(sizeof(sll_node));
    if (!malloc_is_null(header))
    {
        header->next = NULL;
        header->element = 0;    /* 头结点，用于存放链表长度 */
    }   /* end if */
    return header;
}

void insert_node(ptr_sll header, int location)
{
    if (!header_is_null(header))
    {
        if(location_is_valid(location, header))
        {
            ptr_sll new_node = create_node();
            ptr_sll loc = return_address(header, location);
            new_node->next = loc->next;
            loc->next = new_node;
            header->element++;
        }    /* end if */
    }
}

void delete_node(ptr_sll header, int location)
{
    if (!header_is_null(header))
    {
        if (location_is_valid(location - 1, header))
        {
            ptr_sll loc = return_address(header, location - 1);
            ptr_sll tmp = loc->next;
            loc->next = tmp->next;
            free(tmp);
        }
    }
}

int find_node(ptr_sll header, dtype element)
{
    if (!header_is_null(header))
    {
        ptr_sll ptr_cur = header->next;
        int cnt = 1;
        while (ptr_cur != NULL && ptr_cur->element != element)
        {
            cnt++;
            ptr_cur = ptr_cur->next;
        }
        if (ptr_cur == NULL)
        {
            puts("element isn't in the list!");
            cnt = -1;
        }
        return cnt;
    }
    return -1;
}

void traverse_sll(const ptr_sll const header)
{
    if (!header_is_null(header))
    {
        ptr_sll ptr_cur = header->next;
        while (ptr_cur != NULL)
        {
            printf("the value of element : %d\n", ptr_cur->element);
            ptr_cur = ptr_cur->next;
        }
    }
}

ptr_sll clean_sll(ptr_sll header)
{
    if (!header_is_null(header))
    {
        ptr_sll ptr_cur = header, tmp;
        while (ptr_cur != NULL)
        {
            tmp = ptr_cur->next;
            free(ptr_cur);
            ptr_cur = tmp;
        }
        header = NULL;
    }
    return header;
}

/******* 测试代码 *******/

int main(void)
{
    ptr_sll header = create_sll();
    int flag = 0;
    int loc;
    dtype ele = 0;
    while (flag != -1)
    {
        scanf("%d", &flag);
        switch(flag)
        {
            case 1:
                printf("input the location of insert: ");
                scanf("%d", &loc);
                insert_node(header, loc);
                break;
            case 2:
                printf("input the location of delete: ");
                scanf("%d", &loc);
                delete_node(header, loc);
                break;
            case 3:
                traverse_sll(header);
                break;
            case 4:
                printf("input the element that you want find: ");
                scanf("%d", &ele);
                loc = find_node(header, ele);
                printf("loc = %d\n", loc);
                break;
            default:
                break;
        }
    }
    header = clean_sll(header);
    printf("%p\n", header);
    return 0;
}