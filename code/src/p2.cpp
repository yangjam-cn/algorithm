/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 
 * @Description: 利用两个栈实现队列
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 14:36:09
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 15:20:27
 */
#include "../inc/myStack.hpp"
#include <iostream>

class stackQueue
{
    myStack<int> stackPop;
    myStack<int> stackPush;
    
    public:
        ~stackQueue();
        void enqueue(int value);
        void dequeue();
        int get_head();
        bool is_empty();
};

void stackQueue::enqueue(int value)
{
    stackPush.push(value);
}

void stackQueue::dequeue()
{
    if (!stackPop.is_empty())
    {
        stackPop.pop();
    }
    else if (!stackPush.is_empty())
    {
        while (!stackPush.is_empty())
        {
            stackPop.push(stackPush.get_top());
            stackPush.pop();
        }
        stackPop.pop();
    }
}

int stackQueue::get_head()
{
    if (!is_empty())
    {
        if (!stackPop.is_empty())
        {
            return stackPop.get_top();
        }
        else
        {
            while (!stackPush.is_empty())
            {
                stackPop.push(stackPush.get_top());
                stackPush.pop();
            }
            return stackPop.get_top();
        }
    }
    return -1;
}

bool stackQueue::is_empty()
{
    if (stackPop.is_empty() && stackPush.is_empty())
    {
        return true;
    }
    return false;
}

stackQueue::~stackQueue()
{
    while (!is_empty())
    {
        dequeue();
    }
}


int main(void)
{
    using namespace std;
    stackQueue sq;
    int size, value;

    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cin >> value;
        sq.enqueue(value);
    }

    for (int i = 0; i < size / 2; ++i)
    {
        cout <<"head: " << sq.get_head() << endl;
        sq.dequeue();
    }

    for (int i = 0; i < size; ++ i)
    {
        cin >> value;
        sq.enqueue(value);
    }

    while (!sq.is_empty())
    {
        cout << "head: " << sq.get_head() << endl;
        sq.dequeue();
    }

    return 0;
}