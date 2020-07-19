/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: merge_sort.c
 * @Description: 归并排序
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-18 20:28:10
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 12:23:02
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @Function: merge
 * @Description: 对数组中的两个相邻的有序序列进行合并，然后复制回原数组
 * @Input: 
    * arr：数组首元素地址
    * l1：左侧序列起始下标
    * r1：左侧序列结束下标
    * l2：右侧序列起始下标
    * r2：右侧序列结束下标
 * @Output: 序列内元素按升序排列
 * @Return: void
 * @Others: 
 */
void merge(int *arr, int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, k = 0;
    int length = r2 - l1 + 1;    /* 两序列总长度 */
    int *temp = (int *)malloc(sizeof(int) * length);  /* 临时数组用于暂存有序序列 */
    
    while ((i <= r1) && (j <= r2))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= r1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r2)
    {
        temp[k++] = arr[j++];
    }

    for (k = 0; k < length; k++)
    {
        arr[l1 + k] = temp[k];
    }
    free(temp);
}

/**
 * @Function: merge_sort
 * @Description: 归并排序，对数组进行二分
 * @Input: 
    * arr：数组首元素地址
    * left：待排序序列起始下标
    * right：待排序序列结束下标 
 * @Output: 数组序列按升序排列
 * @Return: void
 * @Others: 
 */
void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, mid + 1, right);
    }
}

int main(void)
{
    int length;
    srand((unsigned int)time(NULL));
    scanf("%d", &length);
    int *arr = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    merge_sort(arr, 0, (length - 1));
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}