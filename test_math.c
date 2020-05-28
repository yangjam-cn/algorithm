#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int sum = 0;
    srand((unsigned int)time(NULL));
    char flag = 'a';
    while(flag!= 'q'){
        a = rand()%100;
        b = rand()%100;
        printf("a = %d\tb = %d\n", a, b);
        scanf("%d", &sum);
        if (sum == (a + b))
            printf("思航真聪明！\n");
        scanf("%c", &flag);
    }
    return 0;
}