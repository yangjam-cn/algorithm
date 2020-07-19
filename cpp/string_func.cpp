/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: string_func.cpp
 * @Description: string函数测试
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 19:36:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 19:53:06
 */ 
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    string str1, str2;
    string::iterator it1, it2, it3;
    cin >> str1;
    cin >> str2;
    cout << str1.length() << '\t' << str2.size() << endl;

    str1 += str2;
    cout << str1 << endl;

    cin >> str1;
    it1 = str1.begin() + 1;
    it2 = str2.begin() + 1;
    it3 = str2.end() - 2;
    str1.insert(0, str2);
    cout << str1 << endl;
    str1.insert(it1, it2, it3);
    cout << str1 << endl;

    str1.erase(2, 5);
    cout << str1 << endl;

    cout << str1.substr(2, 5) << endl;

    printf("%s\n", str2.c_str());

    printf("%u\n", str1.find(str2));

    str1.replace(0, 5, str2);
    cout << str1 << endl;

    return 0;
}