#include<stdlib.h>
#include<stdio.h>
typedef struct Stu_Info {
    char name[20];
    int score;
} stu_info;

struct Link_List {
    stu_info ele;
    struct Link_List *next;
};
typedef struct Link_List *llist;

void get_ele(stu_info *ele)
{
    puts("input name:");
    scanf("%s", ele->name);
    puts("input score:");
    scanf("%d", &(ele->score));
}

void print_ele(stu_info ele)
{
    printf("%s\t%d\n", ele.name, ele.score);
}

llist init_list(llist list)
{
    list = (llist)malloc(sizeof(struct Link_List));
    list->next = NULL;
    get_ele(&(list->ele));
    return list;
}

void delete_list(llist list)
{
    free(list);
}

int main(void)
{
    llist list = NULL;
    list = init_list(list);
    print_ele(list->ele);
    delete_list(list);
    return 0;
}

