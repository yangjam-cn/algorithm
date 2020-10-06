/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 10:16:18
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 10:45:40
 */
#include "string1.hpp"
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
    str = new char [len + 1];
    std::strcpy(str, s);
    ++num_strings;
}

/* 复制构造函数 */
String::String(const String & st)
{
    ++num_strings;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

/* 重载赋值运算符,同类型对象赋值 */
String & String::operator=(const String & st)
{
    if (this == &st)                 /* 检查是否给对象自己赋值 */
        return *this;
    delete [] str;                    /* 释放自己占用的空间 */
    len = st.len;
    str = new char [len + 1];    /* 申请新空间保存字符串，深度复制 */
    std::strcpy(str, st.str);
    return *this;                    /* 返回对象引用，用于连续赋值 */
}

/* 重载赋值运算符，通过常量字符串赋值 */
String & String::operator=(const char *s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    return *this;
}

/* 重载[]运算符，可修改 */
char & String::operator[](int i)
{
    return str[i];
}

/* 重载[]运算符，不可修改 */
const char & String::operator[](int i) const
{
    return str[i];
}

/* 重载<运算符 */
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

/* 重载>运算符，通过调用重载的<实现 */
bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, const String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
}