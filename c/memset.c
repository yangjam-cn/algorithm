/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: memset.c
 * @Description: 测试meneset
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 14:21:03
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 14:34:04
 */ 
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", sizeof(int));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 6; i++)
        printf("%d && %x\t", a[i], a[i]);
    putchar('\n');
    memset(a, -1, sizeof(a));
    for (int i = 0; i < 6; i++)
        printf("%d && %x\t", a[i], a[i]);
    putchar('\n');
    memset(a, 1, sizeof(a));
    for (int i = 0; i < 6; i++)
        printf("%d && %x\t", a[i], a[i]);
    return 0;
}