/*
 * @Copyright: 版权说明
 * @File name: singly_linked_list
 * @Description: 单链表实现与测试
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-13 15:26:07
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-13 19:22:00
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0

typedef int data_type;
/* 单链表结点定义 */
typedef struct linked_node
{
    data_type element;
    struct linked_node *next;
    
}linked_node;
typedef linked_node *ptr_linked;

/* 运算定义 */

/* 
 * 创建运算
 * 创建链表头结点，并返回头指针
 */
ptr_linked create_linked_header(void);

/*
 * 清除运算
 * 删除链表中的全部元素
 */
ptr_linked clear_list(ptr_linked header);

/*
 * 插入运算
 * 向链表中插入元素
 */
ptr_linked insert_node(ptr_linked header, int location);

/*
 * 删除运算
 * 删除链表中的某个元素
 */
ptr_linked delete_node(ptr_linked header, data_type element);

/*
 * 搜索运算
 * 查找链表中满足某一条件的元素
 */
ptr_linked find_node(ptr_linked header, data_type element);

/*
 * 更新运算
 * 修改链表中指定元素的值
 */
void update_node(ptr_linked const header, data_type old, data_type new);

/*
 * 访问运算
 * 访问链表中的某个元素
 */
// data_type visit_node(ptr_linked const header, data_type element);

/*
 * 遍历运算
 * 遍历链表中的所有元素
 */
void traverse_list(ptr_linked const header);

/* 运算实现 */

/*
 * 检查malloc()分配内存是否成功
 */
int malloc_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        printf("memeory allocation failure!\n");
        return true;
    }
    else
    {
        return false;
    }
    
}

/*
 * 检查表头是否为NULL
 */
int cheack_header_is_null(ptr_linked header)
{
    if (header == NULL)
    {
        printf("linked list is NULL!\n");
        return true;
    }
    else
    {
        return false;
    }
    
}

/*
 * 创建结点
 */
ptr_linked create_node(void)
{
    ptr_linked ptr = (ptr_linked)malloc(sizeof(linked_node));
    if (!malloc_is_null(ptr))
    {
        puts("input the value of node:");
        scanf("%d", &(ptr->element));
        ptr->next = NULL;
    }
    return ptr;
}

ptr_linked create_linked_header(void)
{
    ptr_linked header = create_node();
    return header;
}

ptr_linked clear_list(ptr_linked header)
{
    if (header != NULL)
    {
        ptr_linked ptr_current = header, temp;
        while (ptr_current != NULL)
        {
            temp = ptr_current->next;
            free(ptr_current);
            ptr_current = temp;
        }
        header = NULL;
    }
    return header;
}

ptr_linked insert_node(ptr_linked header, int location)
{
    ptr_linked ptr_current = header, temp;
    int count;

    if (header == NULL)
    {
        printf("linked list is NULL!\n");
        return header;
    }

    if (location < 0)
    {
        temp = create_node();
        temp->next = ptr_current;
        header = temp;
    }
    else
    {
        for (count =0; count < location && ptr_current->next != NULL; count++)
        {
            temp = ptr_current->next;
            ptr_current = temp;
        }
        temp = create_node();
        temp->next = ptr_current->next;
        ptr_current->next = temp;
    }
    return header;
}

ptr_linked delete_node(ptr_linked header, data_type element)
{
    ptr_linked temp, ptr;
    if (!cheack_header_is_null(header))
    {
        if (element == header->element)
        {
            temp = header->next;
            free(header);
            header = temp;
        }
        else
        {
            ptr = find_node(header, element);
            temp = ptr->next->next;
            free(ptr->next);
            ptr->next = temp;
        }
    }
    return header;
}

ptr_linked find_node(ptr_linked header, data_type element)
{
    if (!cheack_header_is_null(header))
    {
        ptr_linked ptr = header;
        while (ptr->next->element != element)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
    return NULL;
}

void update_node(ptr_linked const header, data_type old, data_type new)
{
    if (!cheack_header_is_null(header))
    {
        if (old == header->element)
        {
            header->element = new;
        }
        else
        {
            ptr_linked ptr = find_node(header, old);
            if (ptr != NULL)
            {
                ptr->next->element = new;
            }
        }
    }
}

void traverse_list(ptr_linked const header)
{
    if (!cheack_header_is_null(header))
    {
        ptr_linked ptr_current = header;
        while (ptr_current != NULL)
        {
            printf("the value of node:%d\n", ptr_current->element);
            ptr_current = ptr_current->next;
        }
    }
}


int main()
{
    ptr_linked header = create_linked_header();
    printf("%p\n", header);
    header = insert_node(header, 0);
    header = insert_node(header, 1);
    header = insert_node(header, 3);
    traverse_list(header);
    header = clear_list(header);
    printf("%p\n", header);
    return 0;
}