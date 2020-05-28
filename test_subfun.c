#include<stdlib.h>
#include<stdio.h>
int *create_ptr(void)
{
    int *ptr;
    int a = 12;
    ptr = &a;
    printf("%p\t%d\n", ptr, *ptr);
    return ptr;
}
int *create_add(int *p)
{
    p = (int *)malloc(sizeof(int));
    printf("%p\n", p);
    return p;
}
int main(void)
{
    int *p1, *p2;
    p1 = create_ptr();
    printf("%p\t%d\n", p1, *p1);
    p2 = create_add(p2);
    printf("%p\n", p2);
    return 0;
}