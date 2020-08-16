#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    clock_t start, end;
    start = clock();
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        printf("%d\t", rand()%100);
    }
    end = clock();
    printf("\ntime = %f\n", (double)(end - start));
    return 0;
}