/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-27 21:57:59
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-27 22:02:27
 */ 

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int n;
    int temp, x, y, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }
    while (q.size() > 1)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }
    cout << ans;
    return 0;
}