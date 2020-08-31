/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 09:35:31
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 10:00:30
 */
#include "../inc/myStack.hpp"
#include <iostream>
using namespace std;

int main(void)
{
    myStack<int> s1;
    int value;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        s1.push(value);
    }
    cout << s1.get_top() << endl;
    cout << s1.get_size() << endl;
    s1.pop();
    s1.pop();
    cout << s1.get_top() << endl;
    cout << s1.get_size() << endl;
    return 0;
}