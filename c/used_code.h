/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: used_code.h
 * @Description: 常用代码 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 13:40:58
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 13:46:02
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_rand_array(int length)
{
    int *arr = (int *)malloc(sizeof(int) * length);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}

void printf_array(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    putchar('\n');
}

void free_array(int *arr)
{
    free(arr);
}