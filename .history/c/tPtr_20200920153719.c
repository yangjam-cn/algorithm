#include <stdio.h>

int main()
{
    int i = 0;
    int ptr_value = (int)&i;
    int *ptr = (int *)ptr_value;
    *ptr = 0xaa;
    printf("%p\t%x", ptr, *ptr);
    return 0;
}