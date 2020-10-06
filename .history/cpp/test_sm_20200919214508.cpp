/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-19 21:37:39
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-19 21:44:19
 */
#include <iostream>

using namespace std;

void fun1()
{
    int a;
    cout << &a << endl;
    int *p = new int;
    if (p != nullptr)
        cout << "new :" << p << endl;
    delete p;
}

int main(void)
{
    int (*pm)(void) = main;
    void (*pf)() = fun1;
    cout << "main = " << pm << endl;
    cout << "fun1 = " << pf << endl
    fun1();
    return 0;
}