/*
 * @Author: youngjam
 * @Date: 2020-04-17 20:13:21
 * @LastEditTime: 2020-04-17 23:35:18
 * @Description: 
 * @Model: 
 * @Input: 
 * @Output: 
 * @logs: 
 */
/*
 *2020年 04月 17日 星期五 20:13:42 CST
 *《算法基础》
 *问题：键 x 是否存在于 n 个键的表 S 中？
 *输入（参数）：正整数 n ；键的数组 S ，其索引范围为0～n-1；键 x 
 *输出：location，x 在表 S 中的位置，若不在 S 中，则为 -1；
*/

/* 顺序搜索 */
#include<stdio.h>
/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void main()
{
    int n = 12;
    int S[12] = {0};
    int location = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        S[i] = i;
    }
    scanf("%d", &x);
    while (location < n && S[location] != x)
        location++;
    if (location == n)
        location = -1;
    printf("location = %d\n", location);
}