/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-19 21:37:39
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-19 21:41:27
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
    void (*p)(void) = mian;
    cout << "main = " << p << endl;
    fun1();
    return 0;
}