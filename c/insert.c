/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: insert.c
 * @Description: 插入排序
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 18:42:45
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 18:57:34
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
 * 当数组只有一个元素，必然有序，新增加元素，则插入当前序列正确位置
 */
void insert(int *arr, int length)
{
    /* 假定首元素有序，从后面元素遍历 */
    for (int i = 1; i < length; i++)
    {
        /* 若遍历元素小于前一有序元素，则逐一向前插入 */
        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); j--)
        {
            swap((arr + j), (arr + j - 1));
        }
    }
}

int main(void)
{
    int length;
    int *arr;

    srand((unsigned int)time(NULL));

    scanf("%d", &length);
    arr = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }

    print_arr(arr, length);

    insert(arr, length);

    print_arr(arr, length);

    free(arr);
    return 0;
}