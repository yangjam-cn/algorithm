/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: quick_power.c
 * @Description: 快速幂
    * 给定正整数a、b，求a^b
    * 若b=0，则res = 1
    * 若b为偶数，则res=a^(b/2)*a^(b/2)
    * 若b为奇数，则res=a*a^(b-1) 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-18 12:07:02
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-18 15:51:32
 */ 
#include <stdio.h>


long quick_power(int a, int b)
{
    long result;
    if (b == 0)
    {
        return 1;
    }
    else if ((b % 2) == 1)
    {
        result = a * quick_power(a, b - 1);
    }
    else
    {
        result = quick_power(a, b / 2);
        result *= result;
    }
    return result;
}

/*
 * 迭代解法
 * 将b写为二进制形式
 * 如13 = 0b_1101
 * a^13 = a^8*a^4*a^0*a^1
 * 记下二进制对应的乘幂，如该位为1则相乘，若该位为0则跳过
 */
long quick_power_iteration(int a, int b)
{
    long res = 1;
    while (b > 0)
    {
        if ((b & 1))
        {
            res = res * a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(void)
{
    int a, b;
    long res1, res2;
    scanf("%d %d", &a, &b);
    res1 = quick_power(a, b);
    res2 = quick_power_iteration(a, b);
    printf("%d^%d = %ld %ld\n", a, b, res1, res2);
    return 0;
}