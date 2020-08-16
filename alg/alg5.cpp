/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-12 14:26:54
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-12 15:59:09
 */
#include <iostream>
#include <cstdlib>

const int INF = 0xfffffff;


int coin_change(int *coin, int coins, int amount);
int coin_change_with_memo(int *coin, int coins, int amount);

int main(void)
{
    using namespace std;

    int coin[3] = {1, 2, 5};
    int amount;
    cin >> amount;

    int nums = coin_change(coin, 3, amount);
    cout << nums << endl;

    nums = coin_change_with_memo(coin, 3, amount);
    cout << nums << endl;

    return 0;
}

int coin_change(int *coin, int coins, int amount)
{
    if (amount < 0)
    {
        return -1;
    }

    if (0 == amount)
    {
        return 0;
    }

    int minNums = INF;
    int nums;
    for (int i = 0; i < coins; i++)
    {
        nums = coin_change(coin, coins, amount - coin[i]);
        if (nums == -1)
        {
            continue;
        }
        if ((nums + 1) < minNums)
        {
            minNums = nums + 1;
        }
    }
    if (minNums == INF)
    {
        minNums = -1;
    }
    return minNums;
}

int coin_change_with_memo(int *coin, int coins, int amount)
{
    if (amount < 0)
    {
        return -1;
    }

    if (0 == amount)
    {
        return 0;
    }

    int *memo = new int [amount + 1];
    
    memo[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        memo[i] = INF;
        for (int j = 0; j < coins; j++)
        {
            /*memo[i] = min(1 + memo[amount - coin[j]])*/
            if (i - coin[j] < 0 || -1 == memo[i - coin[j]])
            {
                continue;
            }
            else
            {
                if (memo[i] > memo[i - coin[j]] + 1)
                {
                    memo[i] = memo[i - coin[j]] + 1;
                }
            }
        }
        if (memo[i] == INF)
        {
            memo[i] = -1;
        }
    }
    int result = memo[amount];
    delete [] memo;
    return result;
}