/*
 * @Author: youngjam
 * @Date: 2020-04-18 21:54:24
 * @LastEditTime: 2020-04-18 22:30:08
 * @Description: 判断x是否在一个大小为n的有序数组中
 * @Input:正整数n；键x；有序（非递减）键数组S 
 * @Output: location，x在数组中的位置
 * @logs: 
 */
/* 伪代码描述 */
/*
index location(low, high)
{
    if (low > high)
        return -1;
    else
        mid = (low + high) / 2;
        if (S[mid] == x)
            return mid;
        else if (S[mid] > x)
            return location(low, mid - 1);
        else
            return location(nid + 1, high);
}
*/
/* 代码实现 */
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

void change_sort(int length, int *S)
{
    for (int i = 0; i < length -1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (S[j] < S[i])
                swap(S + j, S + i);
        }
    }
}

int binsearch(int *S, int low, int high, int x)
{
    if (low > high)
        return -1;
    else {
        int mid = (low + high) / 2;
        if (S[mid] == x)
            return mid;
        else if (S[mid] > x)
            return binsearch(S, low, mid - 1, x);
        else 
            return binsearch(S, mid + 1, high, x);
    }
}

int main()
{
    srand((int)time(0));
    clock_t start, end;
    int length = rand() % 10 + 10;
    int *S = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        S[i] = rand() % 30;
        printf("%d\t", S[i]);
    }
    printf("\n");
    start = clock();
    change_sort(length, S);
    for (int i = 0; i < length; i++)
        printf("%d\t", S[i]);
    printf("\n");
    int x = rand() % 20;
    int location = -1;
    location = binsearch(S, 0, length - 1, x);
    printf("location of %d in the array is %d\n", x, location);
    end = clock();
    printf("time = %f\n", (double)((end - start) / CLOCKS_PER_SEC));
    free(S);
    return 0;
}