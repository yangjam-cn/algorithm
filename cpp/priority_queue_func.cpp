/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: priority_queue_func
 * @Description: 优先队列测试
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-20 14:26:37
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-20 14:55:41
 */ 
#include <queue>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct fruit
{
    string name;
    int price;
    friend bool operator<(const fruit &f1, const fruit &f2)
    {
        return f1.price < f2.price;
    }
};


int main(void)
{
    priority_queue<int> q_int;

    srand((unsigned int)time(NULL));
    int length = rand() % 15;
    
    for (int i = 0; i < length; i++)
    {
        int value = rand() % 100;
        cout << value << " ";
        q_int.push(value);
    }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        if (!(q_int.empty()))
        {
            cout << q_int.top() << " ";
            q_int.pop();
        }
    }
    cout << q_int.size() << endl;

    priority_queue<fruit> q_fruit;
    for (int i = 0; i < 4; i++)
    {
        fruit f1;
        cin >> f1.name;
        cin >> f1.price;
        q_fruit.push(f1);
        
    }
    while (!(q_fruit.empty()))
    {
        cout << q_fruit.top().name << " is " << q_fruit.top().price << "￥" << endl;
        q_fruit.pop();
    }
    return 0;
}