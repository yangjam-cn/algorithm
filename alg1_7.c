/*
 * @Author: youngjam
 * @Date: 2020-04-18 15:00:54
 * @LastEditTime: 2020-04-18 15:16:09
 * @Description: 斐波拉切数列（迭代）
 * @Model: 计算斐波拉切数列第n项
 * @Input: 非负整数n
 * @Output: 斐波拉切数列第n项
 * @logs: 
 */
/* 伪代码描述 */
/*
void fib(int n)
{
    int fib[];
    fib[0] = 1;
    if (n > 0)
        fib[1] = 1;
        for (i = 2; i <= n; i++)
            fib[i] = fib[i - 1] + fib[n - 2];
    return fib[n];
}
*/
/* 代码实现 */
#include<stdio.h>

int fib(int n)
{
    int fib1 = 1, fib2 = 1, fib;
    if (n <= 1)
        fib = 1;
    else {
        while (n-- >=2) {
            fib = fib1 + fib2;
            //fib1 = fib;
            fib2 = fib1;
            fib1 = fib;
        }
    }
    return fib;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("fib(%d) = %d\n", n, fib(n));
    return 0;
}