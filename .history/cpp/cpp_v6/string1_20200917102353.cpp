/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 10:16:18
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 10:23:53
 */
#include "String1.hpp"
#include <cstring>
using std::cin;
using std::cout;

int String::num_strings = 0;

/* 静态函数，只能访问类中的静态成员 */
int String::HowMany()
{
    return num_strings;
}

/* 默认构造函数 */
String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    ++num_strings;
}

/* 构造函数 */
String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    ++num_strings;
}