/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-16 21:23:50
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-16 21:45:24
 */
#ifndef MYTIME_HPP_
#define MYTIME_HPP_
#include <iostream>

class Time
{
        /*私有成员*/
    private:
        int hours;
        int minutes;
    /*公有成员*/
    public:
        Time();                                            /*默认构造函数*/
        Time(int h, int m = 0);                      /*构造函数,并通过默认值进行初试化*/
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time operator+(const Time &t) const;    /*重载+*/
        Time operator-(const Time &t) const;    /*重载-*/
        Time operator*(double n) const;            /*重载**/
        /*友元版本的*重载，通过调用成员函数的重载版本实现*/
        friend Time operator*(double m, const Time &t)
            {return t * m;}
        /*友元版重载<<*/
        friend std::ostream & operator<<(std::ostream & os, const Time & t);
};
#endif
