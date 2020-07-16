/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: find_ele.c
 * @Description: 查找元素
    * 输入一个数n(1<=n<=200),然后输入n个数值各不相同的数，再输入一个数值x，输出这个值再数组中的下标，若不在则输出-1
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 16:03:38
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 16:12:03
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int loc = -1;
    int numbers = 0;
    int element = 0;
    int *arr;
    srand((unsigned int)time(NULL));
    scanf("%d", &numbers);
    arr = (int *)malloc(sizeof(int) * numbers);
    for (int i = 0; i < numbers; i++)
    {
        arr[i] = rand() % 100;
    }
    scanf("%d", &element);
    for (loc = 0; loc < numbers; loc++)
    {
        if (arr[loc] == element)
        {
            break;
        }
    }
    if (loc >= numbers)
    {
        loc = -1;
    }
    printf("loc = %d\n", loc);
    for (int i = 0; i < numbers; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}