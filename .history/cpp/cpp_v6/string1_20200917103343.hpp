/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 10:06:55
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 10:33:43
 */
#ifndef STRING1_HPP_
#define STRING1_HPP_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
    private:
        char *str;
        int len;
        /* 静态成员，所有对象共享 */
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String();
        String(const char *s);
        String(const String &);
        ~String();

        int length() const {return len;}
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;

        friend bool operator<(const String & st, const String & st2);
        friend bool operator>(const String & st, const String & st2);
        friend bool operator==(const String & st, const String & st2);
        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, const String & st);

        static int HowMany();
};

#endif