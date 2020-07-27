/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: good_friend
 * @Description:
    * 有一个叫做数码世界的奇异空间，在数码世界生活许多数码宝贝，其中数码宝贝之间可能是好朋友。并且存在两条规则：
    * 1. A和B是好朋友等价于B和A是好朋友
    * 2. 如果A和C是好朋友，则B和C也是好朋友
    * 现给出这些数码宝贝的好朋友信息，问：可以把这些数码宝贝分为多少组，满足每组的任意两只数码宝贝都是好朋友，且任意两组之间的数码宝贝都不是好朋友？ 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-27 16:38:04
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-27 16:54:43
 */ 
#include <cstdio>

const int N = 100;

int father[N];    /* 存放父结点 */
bool isRoot[N];   /* 记录结点是否为集合的根结点 */

int find_father(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }

    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void union_set(int a, int b)
{
    int faA = find_father(a);
    int faB = find_father(b);
    if (faA != faB)
    {
        father[faB] = faA;
    }
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        union_set(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        isRoot[find_father(i)] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isRoot[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}