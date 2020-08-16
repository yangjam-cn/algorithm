/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 位运算(哈希表)判断字符包含
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 19:36:44
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 19:45:10
 */
#include <string>
#include <iostream>

int main(void)
{
    using namespace std;
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;

    int hash = 0;
    bool isContain = true;
    for (int i = 0; i < str1.length() - 1; i++)
    {
        hash |= (1 << (str1[i] - 'a'));
    }
    for (int i = 0; i < str2.length() - 1; i++)
    {
        if (0 == (hash & (1 << str2[i] - 'a')))
        {
            isContain = false;
            break;
        }
    }
    if (isContain)
    {
        cout << "str2 in str1!" << endl;
    }
    else
    {
        cout << "str2 is new string." << endl;
    }
    return 0;
}