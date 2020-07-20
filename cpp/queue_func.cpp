/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: queue_func.cpp
 * @Description: queue函数测试 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-20 10:58:21
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-20 11:05:58
 */ 
#include <queue>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    queue<int> q;
    srand((unsigned int)time(NULL));
    int length = rand() % 15;
    for (int i = 0; i < length; i++)
    {
        q.push((rand() % 100));
    }
    cout << q.size() << endl;
    cout << "front = " << q.front() << " ** " << "back = " << q.back() << endl;

    for (int i = 0; i < length; i++)
    {
        cout << q.front() << endl;
        q.pop();
    }
    if (q.empty())
    {
        cout << "queue is empty!" << endl;
    }
    else
    {
        cout << "queue isn't enpty!" << endl;
        cout << "front = " << q.front() << endl;
    }
    return 0;
}