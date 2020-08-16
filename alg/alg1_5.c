/*
 * @Author: youngjam
 * @Date: 2020-04-18 08:42:50
 * @LastEditTime: 2020-04-18 09:38:56
 * @Description: 二分搜索
 * @Model: 在n个键组成的非递减排序表S中找到键x的位置
 * @Input: 正整数n；非递减排序表S，其索引为0～n-1；键x
 * @Output: location，键x在表中的索引（若不再表中则返回-1）
 * @logs: 
 */
/* 伪代码描述 */
/*
void binsearch(int n, keytype const S[], keytype x, index &location)
{
    index low = 0, high = n-1, mid = 0;
    location = -1;
    while (low <= high && location == -1) {
        mid = (low + high) / 2;
        if (S[mid] == x)
            location = mid;
        else if (S[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
}
*/
/* 代码实现 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

void binsearch(int n, int *S, int x, int *location)
{
    int low = 0, high = n - 1, mid = 0;
    *location = -1;
    while (low <= high && *location == -1) {
        mid = (low + high) / 2;
        if (S[mid] == x)
            *location = mid;
        else if (S[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main()
{
    srand((int)time(0));
    clock_t start, end;
    start = clock();
    int n = 12;
    int S[12] = {0};
    for (int i = 0; i < 12; i++)
        S[i] = i * 2;
    int x = 6;
    int location = -1;
    binsearch(n, S, x, &location);
    printf("location = %d\n", location);
    end = clock();
    printf("time = %f\n", (double)((end - start) / CLOCKS_PER_SEC));
}