/*
 *2020年 04月 17日 星期五 20:31:48 CST
 *算法1.2:数组成员求和
 *问题：将包含n个数字的数组S中的所有成员加在一起
 *输入：正整数n，数字数组S，其索引值为1～n
 *输出：sum，S中的数字之和
*/
/* 伪代码描述 */
/*
number sum(int n, const number S[])
{
    index i;
    number result;
    for (i = 1; i <= n; i++)
        result = s[i] + result
    return result;
}
*/
/* 具体实现 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>

int sum(int n, int const *s)
{
    int result = 0;
    for (int i = 0; i < n; i++, s++)
        result += *s;
    return result;
}

int main()
{
    srand((int)time(0));
    int n = rand() % 10 + 6;
    int result = 0;
    int *s = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        s[i] = rand() % 20;
    result = sum(n, s);
    for (int i = 0; i < n; i++)
        printf("%d\t", *(s + i));
    printf("\n");
    printf("result = %d\n", result);
    free(s);
    return 0;
}