/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 三步反转
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 19:09:28
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 19:18:15
 */
#include <string>
#include <iostream>

using namespace std;

void reverse(string &str, int start, int end)
{
    while (start < end)
    {
        char temp = str[end];
        str[end--] = str[start];
        str[start++] = temp;
    }
}


int main(void)
{
    string str;
    cin >> str;
    int loc;
    cin >> loc;
    reverse(str, 0, loc - 1);
    reverse(str, loc, str.length() - 1);
    reverse(str, 0, str.length() - 1);
    cout << str << endl;
    return 0;
}