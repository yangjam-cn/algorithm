/*
 *2020年 04月 17日 星期五 22:20:16 CST
 *算法：交换排序
 *问题：将n个键按非递减的顺序排列
 *输入：正整数n；键的数组S，其索引为0~n-1
 *输出：数组S，其键按非递减的顺序排列
*/
/* 伪代码 */
/*
void excangesort(int n, number S)
{
    index i, j;
    for (i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(s[j] < s[i])
                交换s[]j和s[i]
}
*/

/* 代码实现 */
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void exchange_sort(int n, int *s)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[j] < s[i])
                swap(s + j, s + i);
}

int main(void)
{
    srand((int)time(0));
    int n = rand() % 20 + 5;
    int *s = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        s[i] = rand() % 20;
    for (int i = 0; i < n; i++)
        printf("%d\t", s[i]);
    exchange_sort(n, s);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", *(s + i));
    printf("\n");
    free(s);
    return 0;
}