/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: DFS
 * @Description: 
    * 有n件物品，每件物品的重量为w[i]，价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中，使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品的价值之和最大，求最大价值。 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-21 14:44:57
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-21 20:24:55
 */ 
#include <cstdio>

const int maxn = 20;    /* 最大物品数 */
int weight[maxn], value[maxn];    /* weight记录物品重量，value记录物品价值 */
int nums;         /* 物品数 */
int maxWeight;    /* 背包容量 */
int maxValue;     /* 最大价值 */

int per[maxn];   /* 物品序号排列 */ 
bool hashTable[maxn] = {false};    /* 标记物品是否访问 */


/* 全排列方式穷举 */
void permutation(int index)
{
    if (index == nums)    /* 递归边界 */
    {
        int i = 0;    /* 物品序号在排列中的下标 */
        int num;      /* 记录符合背包容量的i值 */
        int total_weight = 0;    /* 物品总重量 */
        int total_value = 0;     /* 物品总价值 */

        /**
         * 从头遍历该排列，将物品加入背包，直到超出退出退出循环；
         * 退出循环时，背包超过容量，应减去该物品，且内循环使用i++，下标超前1
         */
        while (total_weight <= maxWeight)
        {
            total_weight += weight[per[i++]];
        }
        num = i - 2;
        i -= 2;

        /* 对符合重量要求的组合计算其价值 */
        while (i >= 0)
        {
            total_value += value[per[i--]]; 
        }
        /* 打印符合要求的物品重量及总价值 */
        for (int j = 0; j <= num; j++)
        {
            printf("%d", weight[per[j]]);
        }
        putchar('=');
        printf("%d\n", total_value);

        return;
    }
    for (int i = 0; i < nums; i++)
    {
        if (!hashTable[i])
        {
            per[index] = i;
            hashTable[i] = true;
            permutation(index + 1);
            hashTable[i] = false;
        }
    }
}


/**
 * 将每件物品视为结点，加入背包和不加入背包为两条分支，建立二叉树，按此进行递归访问
 */
void DFS_demo(int index, int sumW, int sumV)
{
    /* 递归边界 */
    if (index == nums)
    {
        /* 对符合条件的组合更新最大价值 */
        if (sumW <= maxWeight && sumV > maxValue)
        {
            maxValue = sumV;
        }
        return;
    }

    /* 
     * 每件物品有两种选择，每种选择对应不同的分支
     */
    /* 序号为index的物品不加入背包 */
    DFS_demo((index + 1), sumW, sumV);
    /* 序号为index的物品加入背包 */
    DFS_demo((index + 1), sumW + weight[index], sumV+value[index]);
}


/**
 * 对递归分支进行减枝
 */
void DFS_pruning(int index, int sumW, int sumV)
{
    if (index == nums)
    {
        return;
    }
    
    DFS_pruning(index + 1, sumW, sumV);

    if (sumW + weight[index] <= maxWeight)    /* 对重量进行减枝 */
    {
        if (sumV + value[index] > maxValue)   /* 更新最大价值 */
        {
            maxValue = sumV + value[index];
        }
        /* 只有不超重且价值大于之前时才继续往下递归 */
        DFS_pruning(index + 1, sumW + weight[index], sumV + value[index]);
    }
}

int main(void)
{
    scanf("%d %d", &nums, &maxWeight);

    for (int i = 0; i < nums; i++)
    {
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < nums; i++)
    {
        scanf("%d", &value[i]);
    }
    // permutation(0);
    // DFS_demo(0, 0, 0);
    DFS_pruning(0, 0, 0);
    printf("%d", maxValue);
    return 0;
}