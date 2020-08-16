/* 
    单链表实现
    20200413
*/
/*
/* 修改日志
 * 20200413-创建链表结构及相关基本操作
 *20200414-修正变量作用域引起的错误，将表头传值改为传址
*/
#include<malloc.h>
#include<stdlib.h>
#include "datatype.h"

#define true 1
#define false 0

/* 链表定义 */
typedef struct LinkListNode *link_list;
typedef struct LinkListNode {
    data_type data;
    link_list next;
} list_node;

/* 函数定义 */




/**********函数实现***********/

/* 
 *判断指针是否为空指针 ，并输出提示信息
 *时间复杂度：O(1)
*/
int is_null(void const *const ptr)
{
    if (ptr == NULL) {
        printf("pointer is null!\n");
        return true;
    }
    return false;
}

/*
 *初始化空的表头指针
 *时间复杂度：O(1)
 *200414-参数改为按地址传递
*/
void init_list(link_list *head)
{
    /* 如果表头为null，分配地址并赋初值 */
    if (*head == NULL) {
        *head = (link_list)malloc(sizeof(list_node));
        /* 判断地址是否分配成功，否则异常退出 */
        if (is_null(*head)) {
            exit(-1);
        }
        (*head)->next = NULL;
        get_data(&((*head)->data));
    }
    /* 否则输出提示信息 */
    else {
        printf("list is not empty!\n");
    }
}

/* 
 *链表置空并释放其节点 
 *时间复杂度：O(n)
 *20200414-参数改为按址传递
*/
void empty_list(link_list *head)
{
    /* 若表头非空，则依次释放表节点 */
    if (!is_null(*head)) {
        link_list ptr = *head, backup = NULL;
        while (ptr != NULL) {
            backup = ptr->next;
            free(ptr);
            ptr = backup;
        }
        /* 释放所有节点后，表头置null */
        *head = NULL;
    }
}

/*
 *查找尾节点 
 *时间复杂度：O(n)
*/
link_list find_tail(link_list const head)
{
    link_list ptr = head;
    /* 若链表非空，则指针移到表尾，返回其地址 */
    if (!is_null(head)) {
        while (ptr->next != NULL)
            ptr = ptr->next;
    }
    return ptr;
}

/* 
 *计算链表长度 
 *时间复杂度：O(n)
*/
int length_list(link_list const head)
{
    link_list ptr = head;
    int length = 0;
    /* 遍历节点，记录其长度 */
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }
    return length;
}

/* 
 *创建新节点 
 *时间复杂度：O(1)
*/
link_list new_node(void)
{
    link_list new_node = (link_list)malloc(sizeof(list_node));
    /* 判断节点空间是否分配成功，否则异常退出 */
    if (is_null(new_node)) {
        exit(-1);
    }
    new_node->next = NULL;
    get_data(&(new_node->data));
    return new_node;
}

/* 
 *在表尾增加新节点 
 *时间复杂度：O(n) + O(1)
*/
void add_node(link_list head)
{
    /* 若表头为null，直接返回 */
    if (is_null(head)) {
        return;
    }
    link_list tail = find_tail(head);
    tail->next = new_node();
}

/* 
 *按值查找节点 ,并返回其前驱节点
 *时间复杂度：O(n)
 *20200414-修正当所找元素不在表中会发生越界访问引起的程序异常
*/
link_list find_node(link_list const head, data_type const data)
{
    /* head为null，直接返回 */
    if (is_null(head)) {
        return NULL;
    }
    /* 若要查找的值为表头，返回表头 */
    if (is_equal(head->data, data))
        return head;
    link_list ptr = head;
    /* 遍历节点，按值比较 */
    /* error:当元素不在表中时，会先访问null，再判断其为null */
    //while (!is_equal(ptr->next->data, data) && (ptr->next != NULL)) {
    while((ptr->next != NULL) && !is_equal(ptr->next->data, data)) {
        ptr = ptr->next;
    }
    /* 若遍历结束后，指向表尾，则说明表中没有这个值 */
    if (ptr->next == NULL) {
        printf("not found this data!\n");
    }
    return ptr;
}

/* 
 *在指定的值前面插入节点
 *时间复杂度：O(n)+O(1) 
*/
void insert_node(link_list *head, data_type data)
{
    if (is_null(*head))
        return;
    link_list location = find_node(*head, data);
    link_list node;
    node = new_node();
    /* 若location为head，且查找的值为表头，则在表头前插入 */
    if (location == *head && is_equal((*head)->data, data)) {
        node->next = *head;
        *head = node;
    }
    /* 若表中没有找到这个值，那么在表尾插入新值 */
    else if (location->next == NULL) {
        location->next = node;
    }
    /* 向链表中插入新值 */
    else {
        link_list backup = location->next;
        location->next = node;
        node->next = backup;
    }
}

/*  
 *删除节点
 *时间复杂度：O(1)
*/
void delete_node(link_list *head, data_type data)
{
    if (is_null(*head)) {
        return;
    }
    link_list ptr = find_node(*head, data);
    /* 若要删除的为表头 */
    if (ptr == *head && is_equal((*head)->data, data)) {
        ptr = (*head)->next;
        free(*head);
        *head = ptr;
    }
    /* 删除表头之外的其它节点 */
    else if (ptr->next != NULL) {
        link_list backup = ptr->next;
        ptr->next = backup->next;
        free(backup);
    }
}

/* 
 *打印链表 
 *时间复杂度：O(1)
*/
void print_list(link_list const head)
{
    if (is_null(head))
        return;
    link_list ptr = head;
    /* 遍历节点并打印其值 */
    while (ptr != NULL) {
        print_data(ptr->data);
        ptr = ptr->next;
    }
}

/*
*/

