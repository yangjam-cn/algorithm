/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 15:05:25
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 15:18:43
 */
#include <iostream>
using std::cout;
using std::endl;

void fun(const int &n)
{
    int *p = (int *)&n;
    *p = 12;
    cout << &n << endl;
}

int main(void)
{
    int a = 10;
    cout << a <<  &a << endl;
    fun(a);
    cout << a << endl;
    return 0;
}