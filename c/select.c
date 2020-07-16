/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: select.c
 * @Description: 选择排序 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 16:51:36
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 17:08:35
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(const int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    putchar('\n');
}

/*
 * 遍历数组，标记最小的数，然后与数组第一位元素交换
 * 重复遍历，标记改轮最小的数，与指定位置元素交换
 */
void select(int *arr, int length)
{
    int min = 0;    /* 最小元素位置标记 */
    for (int i = 0; i < length - 1; i++)
    {
        min = i;   /* 初始为遍历起始位置 */ 
        for (int j = (i + 1); j < length; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;    /* 更新最小元素标记 */
            }
        }
        swap((arr + i), (arr + min));
    }
}

int main(void)
{
    int length = 0;
    int *arr = NULL;
    srand((unsigned int)time(NULL));
    scanf("%d", &length);
    arr = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
    print_arr(arr, length);
    select(arr, length);
    print_arr(arr, length);
    return 0;
}