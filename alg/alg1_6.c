/*
 * @Author: youngjam
 * @Date: 2020-04-18 12:36:43
 * @LastEditTime: 2020-04-18 12:44:17
 * @Description: 斐波拉切数列（递归）
 * @Model: 确定斐波拉切数列第n项
 * @Input: 非负整数n
 * @Output: 斐波拉切数列第n项
 * @logs: 
 */
/* 伪代码描述 */
/*
int fib(int n)
{
    if(n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
*/
/* 代码实现 */
#include<stdio.h>
int fib(int n)
{
    if (n <= 1)
        return 1;
    else   
        return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    int n = 0;
    printf("input the value of n:\t");
    scanf("%d", &n);
    printf("the fib(%d) = %d\n", n, fib(n));
    return 0;
}
