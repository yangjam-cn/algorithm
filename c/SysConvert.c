/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: SysConvert.c
 * @Description: 进制转换
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 16:30:54
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 16:44:40
 */ 
#include <stdio.h>
int main(void)
{
    int number = 0;
    int d = 0;
    int rem;
    char arr[32];
    int cnt = 0;
    scanf("%d %d", &number, &d);
    do
    {
        rem = number % d;
        number /= d;
        if (rem >= 0 && rem <= 9)
        {
            arr[cnt++] = (char)('0' + rem);
        }
        else
        {
            arr[cnt++] = (char)('a' + rem - 10);
        }
    } while (number != 0);
    while (cnt > 0)
    {
        printf("%c", arr[--cnt]);
    }
    return 0;
}