// 遍历单向链表
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define MaxLength 20

typedef struct LinkListNode{
    char name[MaxLength];
    // char *name;
    int student_ID;
    int math;
    int english;
    struct LinkListNode *next;
}llnode;
typedef llnode *llist;

llist init_list(void)
{
    llist list = (llist)malloc(sizeof(llnode));
    if (list == NULL) {
        printf("init error!\n");
        exit(-1);
    }
    else {
        list->next = NULL;
        strcpy(list->name, "list_head");
        list->student_ID = 0;
        list->math = 0;
        list->english = 0;
        return list;
    }
}

llist add_node()
{
    llist new_node = (llist)malloc(sizeof(llnode));
    if (new_node == NULL) {
        printf("add node failed!\n");
        exit(-1);
    }
    else {
        new_node->next = NULL;
        printf("input student name: ");
        scanf("%s", new_node->name);
        printf("input student ID:  ");
        scanf("%d", &new_node->student_ID);
        printf("input math grade:  ");
        scanf("%d", &new_node->math);
        printf("input English grade:  ");
        scanf("%d", &new_node->english);
        return new_node;
    }
}

void travel_list(llist head)
{
    if (head != NULL) {
        llist ptr = head->next;
        float msum = 0, esum = 0, snum = 0;
        while (ptr != NULL) {
            printf("name: %s\tID: %d\tmath: %d\tenglish: %d\n", ptr->name, ptr->student_ID, ptr->math, ptr->english);
            msum += ptr->math;
            esum += ptr->english;
            snum ++;
            ptr = ptr->next;
        }
        if (snum != 0) {
            printf("===================\n");
            printf("average grade: math = %.2f\tenglish = %.2f\n", msum / snum, esum / snum);
        }
    }
}

void free_list(llist head)
{
    llist ptr = head, temp;
    while (ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    head = NULL;
}

int main(void)
{
    llist head = init_list();
    llist ptr = head;
    int select = 0;
    while(select != 2) {
        printf("(1) add node; (2) leave\n");
        scanf("%d", &select);
        if (select == 1) {
            ptr->next = add_node();
            ptr = ptr->next;
        }
    }
    travel_list(head);
    free_list(head);
    return 0;
}
