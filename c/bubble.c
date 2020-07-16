/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: bubble.c
 * @Description: 冒泡排序
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 13:27:42
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 14:14:20
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
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
 * @Function: bubble
 * @Description: 利用冒泡排序对数组进行排序
 * @Input: 
    * arr：数组首元素地址
    * length：数组长度
 * @Output: 按升序排序好的数组
 * @Return: 无返回值
 * @Others: 
    *算法描述：
    *遍历数组，依次比较相邻元素，若逆序则交换位置，一轮遍历后，最大元素必然处于最后位置
    *重复上述遍历操作，每轮遍历必然有一元素排列到指定位置
 */
void bubble(int *arr, int length)
{
    /* 遍历一次，至少有一元素排在指定位置，即n-1次后，所有元素排列好 */
    for (int i = 0; i < (length - 1); i++)
    {
        /* 每遍历一次，需要遍历的元素减1 */
        for (int j = 0; j < (length - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

void bubble_flag(int *arr, int length)
{
    bool flag = false;   /* 排序完成标志 */
    for (int i = 0; (i < (length - 1)) && (!flag); i++)
    {
        flag = true;    /* 假定所有元素已排列完成 */
        for (int j = 0; j < (length - 1) - i; j++)
        {
            /* 当一轮遍历中，不发生元素交换，则说明所有元素已排好序 */
            if (arr[j] > arr[j + 1])
            {
                swap((arr + j), (arr + j + 1));
                flag = false;
            }
        }
    }
}

int main(void)
{
    int num = 0;
    int *arr;
    srand((unsigned int)time(NULL));
    scanf("%d", &num);
    arr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 100;
    }
    print_arr(arr, num);
    bubble_flag(arr, num);
    print_arr(arr, num);
    return 0;
}
