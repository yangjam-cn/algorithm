/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: full_permutation.c
 * @Description: 全排列问题
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 21:55:57
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-21 15:15:19
 */ 
#include <stdio.h>
#include <stdbool.h>
#define maxn 11
int n; 
int P[maxn]; 
bool hashTable[maxn] = {false};
void generateP(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false; 
        }
    }
}

int main()
{
    n = 4;
    generateP(1);
    return 0;
}

