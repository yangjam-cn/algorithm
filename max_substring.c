/*
 问题：求解最大子列和问题
 2020.4.10
 youngjam
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 12

int max3(int a, int b, int c)
{
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}


/*
/* 暴力法求解，遍历所有结果
/* 时间复杂度O(n^2)
*/
int max_substring1(int *arr, int length)
{
    int max_sum = 0, now_sum = 0;
    for (int i = 0; i < length; i++) {  //  i为子列起始位置
        now_sum = 0;
        for (int j = i; j < length; j++) {  //  j为子列终止位置
            now_sum += arr[j];      //  now_sum记录遍历过程中的子列和
            if (now_sum > max_sum)      //  max_sum记录最大子列和
                max_sum = now_sum;  
        }
    }
    return max_sum;
}

/*
/* 分治法求解子列和问题
/* 将序列均分为两段，则最大子列可能出现在三个位置
/* 1.左侧序列；2.右侧序列;3.中间位置，跨越两侧
/* 当位于左右两侧时，序列可视为新的独立序列，即可用递归解决
/* 当处于中间位置时，序列必从中间位置向两侧增长
/* 时间复杂度O(nlogn)
*/
int max_substring2(int *arr, int start, int end)
{
    if (start == end)      //  当序列只有一个元素时，最大子串和即为其本身
        return arr[start];
    int mid = (start + end) / 2;
    int left_max, right_max;
    left_max = max_substring2(arr, start, mid);     //  求解左侧最大子串和
    right_max = max_substring2(arr, mid + 1, end);  // 求解右侧最大字串和
    int left_sum = 0, right_sum = 0;
    int left_sum_max = 0, right_sum_max = 0;
    /* 
    /* 从中间向两侧求解最大子串 
    /* 假定max_sub = left + right,则left 和right必分别为左右两侧从中间向两侧增长的最大子串
    */
    for (int  i = mid; i >= start; i--) {       
        left_sum += arr[i];
        if (left_sum > left_sum_max)
            left_sum_max = left_sum;
    }
    for (int i = mid + 1; i <= end; i++) {
        right_sum += arr[i];
        if (right_sum > right_sum_max)
            right_sum_max = right_sum;
    }
    return max3(left_max, right_max, right_sum_max + left_sum_max);
}


/*
/* 分析法求解最大字串问题
/* 记p[i] = a[0] + ... + a[i]
/* 则子串sub_sum[i, j] = p[j] - p[i - 1],使得p[j] - p[i-1]最大即可
/* 时间复杂度O(n)
*/
int max_substring3(int *arr, int length)
{
    int sum[length];
    sum[0] = arr[0];
    int min = 0, max = sum[0];
    for (int i = 1; i < length; i++) {
        sum[i] = sum[i - 1] + arr[i];
        if (min > sum[i])
            min = sum[i];
        if (max < (sum[i] - min))
            max = sum[i] - min;
    }
    return max;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    int a[N], max_sum;
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 30 - 15;
        printf("%d\t", a[i]);
    }
    max_sum = max_substring1(a, N);
    printf("\nmax_sub_sum = %d\n", max_sum);
    max_sum = max_substring2(a, 0, N - 1);
    printf("\nmax_sub_sum = %d\n", max_sum);
    max_sum = max_substring3(a, N);
    printf("\nmax_sub_sum = %d\n", max_sum);
    return 0;
}