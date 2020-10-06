/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-19 15:41:49
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-19 15:45:38
 */
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str1, str2;
    char ch;

    int M = 234;
    int N = 2;
    while (M > 0)
    {
        ch = (M % N) + '0';
        str1 = str1 + ch;
        M = M / N;
    }
    cout << str1;
    rerurn 0;
}