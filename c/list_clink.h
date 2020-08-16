/*
* 2020.1.5
* 循环链表实现
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* define const value */
#define Max_Length 20
#define False 0
#define True 1

/* define data type */
typedef struct Student_Info {
    char name[Max_Length];
    long id;
    short score;
} data_type;

void get_element(data_type *element)
{
    printf("input the name:");
    scanf("%s", element->name);
    printf("input the id:");
    scanf("%ld", &(element->id));
    printf("input the score:");
    scanf("%hd", &(element->score));
}

void print_element(data_type element)
{
    printf("name:%s\tid:%ld\tscore:%d\n", element.name, element.id, element.score);
}

/* define circal linked list */
struct CLink_Node {
    data_type element;
    struct CLink_Node *next;
};
typedef struct CLink_Node cl_node;
typedef struct CLink_Node *cl_list;

int is_null(cl_list list)
{
    return list == NULL ? True : False;
}

cl_list init_clist(void)
{
    cl_list list = (cl_list)malloc(sizeof(cl_node));
    if (!is_null(list)) {
        get_element(&(list->element));
        list->next = list;
        return list;
    }
    else {
        puts("No space to save the list!");
        return NULL;
    }
}

void delete_clist(cl_list list)
{
    cl_list head = list;
    if (!is_null(list)) {
        cl_list temp;
        do {
            temp = list->next;
            free(list);
            list = temp;
        }while(list != head);
    }
    else
        puts("list is null!");
}

cl_node *new_node(void)
{
    cl_node *new_node = (cl_node *)malloc(sizeof(cl_node));
    if (!is_null(new_node)) {
        get_element(&(new_node->element));
        new_node->next = NULL;
        return new_node;
    }
    else {
        printf("Failed to create space to save new node!\n");
        return NULL;
    }
}

void add_node(const cl_list list)
{
    if (!is_null(list)) {
        cl_node * node = list;
        while (node->next != list)
            node = node->next;
        node->next = new_node();
        node = node->next;
        node->next = list;
    }
    else 
        puts("list is null!");
}

void print_clist(const cl_list list)
{
    if (!is_null(list)) {
        cl_node *node = list;
        do{
            print_element(node->element);
            node = node->next;
        }while(node != list);
    }
}

