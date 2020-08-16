/*
* 2020.1.4
* 基于链表结构的列表实现
*/
#include<stdio.h>
#include<stdlib.h>

#define Max_Length 20
#define False 0
#define True 1

/* 数据类型定义 */
typedef struct Student_Info {
    char name[Max_Length];
    int score;
} Data_Type;

/* 链表节点定义 */
struct Linked_Node {
    Data_Type element;
    struct Linked_Node * next;
};
typedef struct Linked_Node linked_node;
typedef linked_node * linked_list;

/* 自定义数据操作 */
/* 从输入设备获取数据输入 */
void get_element(Data_Type *element)
{
    puts("input the name:");
    scanf("%s", element->name);
    puts("input the score:");
    scanf("%d", &(element->score));
}

void print_element(const Data_Type element)
{
    printf("%s\t%d\n", element.name, element.score);
}

/* 链表操作 */
static int is_null(linked_list list)
{
    if (list == NULL)
        return True;
    else
        return False;
}

linked_list init_list(linked_list list)
{
    list = (linked_list)malloc(sizeof(linked_node));
    if (is_null(list)) {
        puts("No space to save the list!");
        exit(-1);
    }
    else {
        list->next = NULL;
        return list;
    }
}

linked_node *new_node()
{

    linked_node *new = (linked_node *)malloc(sizeof(linked_node));
    if (!is_null(new)) {
        get_element(&(new->element));
        new->next = NULL;
        return new;
    }
    else {
        puts("No space to save the new node!");
        exit(-1);
    }
}

void add_node(linked_list list)
{
    linked_node *node = list;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node();
}

void print_list(linked_list list)
{
    linked_node *node = list->next;
    while (node != NULL) {
        print_element(node->element);
        node = node->next;
    }
}

void delete_list(linked_list list)
{
    linked_list list_node = list, temp;
    while (list_node != NULL) {
        temp = list_node->next;
        free(list_node);
        list_node = temp;
    }
}