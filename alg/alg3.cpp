/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 全排列的递归实现
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 19:50:16
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 20:09:11
 */
#include <iostream>
#include <algorithm>

using namespace std;


void full_perm(int *perm, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            cout << perm[i];
        }
        cout << endl;
    }
    else
    {
        full_perm(perm, start + 1, end);
        for (int i = start + 1; i <= end; i++)
        {
            swap(perm[start], perm[i]);
            full_perm(perm, start + 1, end);
            swap(perm[start], perm[i]);
        }
    }
    
}

int main(void)
{
    int length;
    cin >> length;
    int *perm = new int [length];
    for (int i = 0; i < length; i++)
    {
        perm[i] = i + 1;
    }
    full_perm(perm, 0, length - 1);
    return 0;
}