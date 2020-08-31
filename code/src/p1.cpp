/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p1.cpp
 * @Description: 设计一个可以返回最小元素的栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 10:20:44
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 14:57:37
 */
#include "../inc/myStack.hpp"
#include <iostream>

struct getMinStack
{
    myStack<int> stackData;    /*保存元素*/
    myStack<int> stackMin;     /*保存当前栈中最小元素*/
};

/*
func：元素入栈
description:
数据栈正常入栈
若最小栈为空，将入栈元素加入最小栈
若入栈元素小于等于栈顶元素，则将其压入最小栈栈顶；否则跳过该元素
*/
void push(int data, getMinStack *pStack)
{
    pStack->stackData.push(data);
    if (pStack->stackMin.is_empty() || data <= pStack->stackMin.get_top())
    {
        pStack->stackMin.push(data);
    }
}

/*
func：元素出栈
description:
数据栈正常弹出
若弹出元素与最小栈元素相等，则最小栈弹出栈顶元素；否则跳过
*/
void pop(getMinStack *pStack)
{
    if (!pStack->stackData.is_empty())
    {
        int data = pStack->stackData.get_top();
        pStack->stackData.pop();
        if (data == pStack->stackMin.get_top())
            pStack->stackMin.pop();
    }
}

int get_top(getMinStack *pStack)
{
    if (!pStack->stackData.is_empty())
    {
        return pStack->stackData.get_top();
    }
    return -1;
}

bool is_empty(getMinStack *pStack)
{
    return pStack->stackData.is_empty();
}

int get_min(getMinStack *pStack)
{
    if (!is_empty(pStack))
    {
        return pStack->stackMin.get_top();
    }
    return -1;
}

int main(void)
{
    using std::cout;
    using std::cin;

    getMinStack st;
    int size, value;

    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cin >> value;
        push(value, &st);
    }

    while (!is_empty(&st))
    {
        cout << get_min(&st) << '\t' << get_top(&st) << '\n';
        pop(&st);
    }
    
    return 0;
}