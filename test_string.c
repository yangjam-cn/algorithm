#include<stdio.h>
#include<string.h>

int main(void)
{
    char *s1 = "hello, visual code!";
    char s2[30];
        printf("input the string:");
        gets(s2);
        printf("%d", strcmp(s1, s2));
        if (!strcmp(s1, s2)) {
            printf("s1 and s2 is same!\n");
        }
        else {
            printf("string is different!\n");
        }
    return 0;
}