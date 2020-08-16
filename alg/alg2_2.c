/*
 * @Author: youngjam
 * @Date: 2020-04-19 07:43:11
 * @LastEditTime: 2020-04-19 18:27:29
 * @Description: 合并排序
 * @logs: 
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

/**
 * @description: 将两个有序数组合并为一个有序数组
 * @input:正整数h和m；有序键数组U和V
 * @output: 数组S，其索引为0～h+m-1，在单个有序数组中包含U和V的键
 */
/* 伪代码描述 */
/*
int i = j = k = 0;
while i < h && j < m:
    if U[i] < V[j]
        S[k++] = U[i++];
    else:
        S[k++] = V[i++];
if i >= h:
    copy U[j]-U[m-1] to S[]
else:
    copy V[i]-V[h-1] to S[]
*/
void merge(int h, int m, int *S, int const *U, int const *V)
{
    int i = 0, j = 0, k = 0;
    while (i < h && j < m) {
        if (U[i] < V[j])
            S[k++] = U[i++];
        else 
            S[k++] = V[j++];
    }
    if (i >= h) {
        while (j < m)
            S[k++] = V[j++];
    }
    else {
        while (i < h)
            S[k++] = U[i++];
    }
}

/**
 * @description: 将n个键的数组按非递减排序
 * @input: 正整数n，含n个键的数组S
 * @output: 按非递减排序的数组S
 */
/* 伪代码描述 */
/*
void merge_sort(int n, int S[]){
    int h = n / 2, m = n - h;
    int U[h] = {S[0] ~ S[h - 1]};
    int V[m] = {S[h] ~ S[n]};
    merge_sort(h, U);
    merge_sort(m, V);
    merge(h, m, U, V, S);
}
*/
void merge_sort(int n, int *S)
{
    if (n > 1) {
        int h = 0, m = 0;
        h = n / 2;
        m = n - h;
        int *U = (int *)malloc(sizeof(int) * h);
        int *V = (int *)malloc(sizeof(int) * m);
        for (int i = 0; i < h; i++)
            U[i] = S[i];
        for (int i = 0; i < m; i++)
            V[i] = S[h + i];
        merge_sort(h, U);
        merge_sort(m, V);
        merge(h, m, S, U, V);
        free(U);
        free(V);
    }
}

/**
 * @description: 将原地划分为两个有序子数组合并为单一有序数组
 * @input: 子数组划分索引，及有序排列的子数组
 * @output: 合并后的有序数组
 */
/* 伪代码描述 */
/*
void merge(low, mid, high, S[]) {
    int U[0 ~ high - low];
    i = low, j = mid+1, k=0;
    while (i <= mid && j <= high)
        if (S[i] < S[j])
            U[k++] = S[i++];
        else
            U[k++] = S[j++];
    if (i > mid)
        copy S[j]~S[high] to U[k]~U[high - low];
    else
        copy S[i]~S[mid] to U[k]~U[high - low];
    copy U to S[low] ~ S[high];
}
*/
void merge2(int low, int mid, int high, int *const S)
{
    int *U = (int *)malloc(sizeof(int ) * (high - low + 1));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (S[i] < S[j])
            U[k++] = S[i++];
        else 
            U[k++] = S[j++];
    }
    if (i > mid) {
        while (j <= high)
            U[k++] = S[j++];
    }
    else {
        while (i <= mid)
            U[k++] = S[i++];
    }
    /*********************/
    // for (int i = 0; i < k; i++)
        // S[low + i] = U[i];
    /*********************/
    /*
     *分析，执行完以上循环，k = mid+1-low+high+1-(mid+1) = high-low+1
     *故先执行k--，从high-low开始往前复制
     *终止条件为 >0，先使用 k(1>0) 进行循环条件比较，再执行 k--(k=0)
    */
    // while ((k--) >0){
    //     S[low + k] = U[k];
    // }
    /********************/
    while (k > 0){
        S[low + k] = U[--k];        
        /*只能使用 --k，而不能 k--，式子从左侧开始执行，使得两侧k值不同步*/
    }
    free(U);
}

/**
 * @description: 将n个键按非递减排序
 * @input: 数组S及其键的个数n
 * @output: 按非递减排序的数组S
 */
/* 伪代码描述 */
/*
void merge_sort(int low, int high, int S[]) {
    if (low < high)
        mid = (low + high) / 2;
        merge_sort(low, mid, S);
        merge_sort(mid + 1, high, S);
        merge(low, mid, high, S);
}
*/
void merge_sort2(int low, int high, int *const S)
{
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort2(low, mid, S);
        merge_sort2(mid + 1, high, S);
        merge2(low, mid, high, S);
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
    printf("\n");
    // merge_sort(n, S);
    merge_sort2(0, n - 1, S);
    for (int i = 0; i < n; i++)
        printf("%d\t", S[i]);
    puts("");
    free(S);
    end = clock();
    printf("time = %f\n", (double)((end - start) / CLOCKS_PER_SEC));
    return 0;
}
