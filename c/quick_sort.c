/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: quick_sort.c
 * @Description: 快速排序
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 12:49:05
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 13:38:22
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @Function: partition
 * @Description: 以arr[left]为基准值进行划分，使得左侧小于等于基准值，右侧大于基准值
 * @Input: 
    * arr：数组首元素地址
    * left：序列起始下标
    * right：序列结束下标 
 * @Output: 序列按基准值进行划分，划分后左侧不大于基准值，右侧均大于下标
 * @Return: 划分完成后基准值在序列中的下标
 * @Others: 
    * 选择基准值为arr[left]，左右侧游标分别指向序列首尾
    * 滑动右侧游标，当游标所指向的值小于等于基准值时，赋值给右侧游标所指向的值
    * 滑动左侧游标，当游标所指向的值大于基准值时，复制给左侧游标所指向的值
    * 当左右游标相等时，其值即为基准值在序列中的下标
 */
int partition(int *arr, int left, int right)
{
    int temp = arr[left];
    while (left < right)
    {
        while ((left < right) && (temp < arr[right]))
        {
            right--;
        }
        arr[left] = arr[right];
        while ((left < right) && (temp >= arr[left]))
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[right] = temp;
    return right;
}

/**
 * @Function: quick_sort
 * @Description: 快速排序
 * @Input: 
    * arr：数组首元素下标
    * left：序列起始下标
    * right：序列结束下标
 * @Output: 数组按升序排列
 * @Return: void
 * @Others: 
 */
void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int loc = partition(arr, left, right);
        quick_sort(arr, left, loc - 1);
        quick_sort(arr, loc + 1, right);
    }
}

int main(void)
{
    int length;
    scanf("%d", &length);
    int *arr = (int *)malloc(sizeof(int) * length);
    srand((unsigned int)time(NULL));
    for (short i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
    for (short i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    quick_sort(arr, 0, (length - 1));
    for (short i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}