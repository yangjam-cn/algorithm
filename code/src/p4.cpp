/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 20:07:32
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 20:25:42
 */
#include "../inc/myStack.hpp"
#include <iostream>

void sort_stack(myStack<int> &sp)
{
    if (sp.is_empty() || sp.get_size() == 1)
    {
        return;
    }
    myStack<int> tmpStack;
    while (!sp.is_empty())
    {
        int data = sp.get_top();
        sp.pop();

        while (!tmpStack.is_empty() && data > tmpStack.get_top())
        {
            sp.push(tmpStack.get_top());
            tmpStack.pop();
        }
        tmpStack.push(data);
    }
    while (!tmpStack.is_empty())
    {
        sp.push(tmpStack.get_top());
        tmpStack.pop();
    }
}

int main(void)
{
    using std::cout;
    using std::cin;

    myStack<int> s;
    int size, value;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cin >> value;
        s.push(value);
    }

    sort_stack(s);

    while (!s.is_empty())
    {
        cout << "top: " << s.get_top() << '\n';
        s.pop();
    }
    return 0;
}