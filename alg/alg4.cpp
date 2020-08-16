/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-12 13:31:02
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-12 14:11:00
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>


/*递归解法*/
int fib(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (1 == n | 2 == n)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}


/*带备忘录的递归，自顶向下*/
int fib_with_memo(int *memo, int n)
{
    if (1 == n || 2 == n)
    {
        return 1;
    }

    if (memo[n] != 0)
    {
        return memo[n];
    }
    else
    {
        memo[n] = fib_with_memo(memo, n - 1) + fib_with_memo(memo, n - 2);
        return memo[n];
    }
}


int fib_set_memo(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int *memo = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        memo[i] = 0;
    }

    int result = fib_with_memo(memo, n);
    free(memo);
    return result;
}


/*模拟动态规划自底向上*/
int fib_with_memo_down_to_top(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (1 == n || 2 == n)
    {
        return 1;
    }

    int *memo = (int *)malloc(sizeof(int) * (n + 1));
    memo[1] = memo[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i -2];
    }
    int result = memo[n];
    free(memo);
    return result;
}

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    int n;
    clock_t start, end;
    cin >> n;

    start = clock();
    cout << fib(n) << endl;
    end = clock();
    cout << (end - start) << endl;

    start = clock();
    cout << fib_set_memo(n) << endl;
    end = clock();
    cout << (end - start) << endl;

    start = clock();
    cout << fib_with_memo_down_to_top(n) << endl;
    end = clock();
    cout << end - start << endl;

    return 0;
}
/*
input = 40; time = 863:3:1
*/