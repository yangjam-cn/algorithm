/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: two_pointers.c
 * @Description: 双游标法
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-18 18:33:26
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-18 20:07:44
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 函数名：merge
 * 函数功能：合并两个有序数组
 * 输入参数：
    * arr1：数组1的的首元素地址
    * len1：数组1的长度
    * arr2：数组2的首元素地址
    * len2：数组2的长度
    * dest：合并后数组的首元素地址
 * 输出参数：void
 * 函数说明：
    * 设置两个游标，分别指向两个数组元素，较小者复制到目标数组，移动对应的游标 
 */
void merge(int *arr1, int len1, int *arr2, int len2, int *dest)
{
    int i = 0, j = 0, k = 0;
    while ((i < len1) && (j < len2))
    {
        if (arr1[i] <= arr2[j])
        {
            dest[k++] = arr1[i++];
        }
        else
        {
            dest[k++] = arr2[j++];
        }
    }
    if ((i == len1) && (j < len2))
    {
        do
        {
            dest[k++] = arr2[j++];
        } while (j < len2);
        
    }
    else
    {
        do
        {
            dest[k++] = arr1[i++];
        } while (i < len1);
    }
}

/*
 * 函数名称：bubble
 * 函数功能：对数组进行冒泡排序，按升序排列
 * 输入参数
    * arr：数组首元素地址
    * len：数组长度
 * 输出参数：void
 * 函数说明：
 */
void bubble(int *arr, int len)
{
    bool flag = false;
    for (int i = 0; (i < len - 1) && (!flag); i++)
    {
        flag = true;
        for (int j = 0; j < (len -1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = false;
            }
        }
    }
}

/*
 * @Function: output
 * @Description: 将数组打印到屏幕
 * @Input: 
    * arr：数组首元素地址
    * len：数组长度 
 * @Output: 将数组输出到屏幕
 * @Return: void
 * @Others: 
 */
void output(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

/*
 * @Function: find
 * @Description: 给定数值sum，在有序数组中查找使得a[i]+a[j]=sum的下标
 * @Input: 
    * arr：有序数组首元素地址
    * len：数组长度
    * sum：待查找的值 
 * @Output: 像屏幕输出满足条件的下标
 * @Return: void
 * @Others: 
    * 设定两个游标分别指向首尾元素，依据遍历条件逐步向内搜索 
 */
void find(int *arr, int len, int sum)
{
    int i = 0, j = len - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == sum)
        {
            printf("arr[%d] = %d, arr[%d] = %d\n", i, arr[i], j, arr[j]);
            return;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main(void)
{
    int len1, len2;
    int sum;
    srand((unsigned int)time(NULL));
    
    scanf("%d %d", &len1, &len2);
    int *arr1 = (int *)malloc(sizeof(int) * len1);
    int *arr2 = (int *)malloc(sizeof(int) * len2);
    int *arr = (int *)malloc(sizeof(int) * (len1 + len2));

    for (int i = 0; i < len1; i++)
    {
        arr1[i] = rand() % 100;
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = rand() % 100;
    }

    output(arr1, len1);
    output(arr2, len2);

    bubble(arr1, len1);
    bubble(arr2, len2);
    merge(arr1, len1, arr2, len2, arr);
    output(arr, (len1 + len2));

    scanf("%d", &sum);
    find(arr, (len1 + len2), sum);

    free(arr1);
    free(arr2);
    free(arr);
    return 0;
}