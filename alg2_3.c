/*
 * @Author: youngjam
 * @Date: 2020-04-19 22:20:08
 * @LastEditTime: 2020-04-19 23:01:17
 * @Description: 快速排序
 * @logs: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/**
 * @description: 分割用于快速排序的数组
 * @input: 数组索引low和high，及待排序数组S
 * @output: 数组分割点的索引pivot，以其为界，数组被划分为两半
 */
/* 伪代码描述 */
/*
param:low, high, S[];
pivot = low;
j = low;
for i = low + 1 to high
    if S[i] < S[pivot]:
        swap(s[i], S[++j]);
swap(s[pivot], s[j]);
pivot = j;
*/
int partition(int low, int high, int *S)
{
    int pivot = low;    //划分数组的中心点
    int location = low + 1;     //小于中心点的元素的交换位置
    for (int i = low + 1; i <= high; i++){
        if (S[i] < S[pivot]) {
            swap(S + i, S + location);      //将小于中心点的元素交换到左侧
            location++;     //每找到一个元素，标记后移
        }
    }
    pivot = location - 1;       //中心点在数组中的正确索引
    swap(S + pivot, S + low);   
    return pivot;
}

/**
 * @description: 将数组S按非递减排序
 * @input: 数组索引low，high；数组S
 * @output: 按非递减排序的数组S
 */
/* 伪代码描述 */
/*
param:low, high, S[];
if low < high:
    pivot = partition(low, high, S);
    quickSort(low, pivot - 1, S);
    quickSort(pivot + 1, high, S);
*/
void quick_sort(int low, int high, int *S)
{
    if (low < high) {
        int pivot = partition(low, high, S);
        quick_sort(low, pivot - 1, S);
        quick_sort(pivot + 1, high, S);
    }
}

int main()
{
    srand((int)time(0));
    clock_t start, end;
    start = clock();
    int n = rand() % 20 + 10;
    int *S = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        S[i] = rand() % 30;
        printf("%d\t", S[i]);
    }
    puts("");
    quick_sort(0, n - 1, S);
    for (int i = 0; i < n; i++)
        printf("%d\t", S[i]);
    puts("");
    free(S);
    end = clock();
    printf("time = %f\n", (double)((end - start) / CLOCKS_PER_SEC));
    return 0;
}