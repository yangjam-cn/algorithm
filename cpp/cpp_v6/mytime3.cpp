/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-16 21:32:00
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-16 21:47:11
 */
#include "mytime3.hpp"

Time::Time()
{
    hours = minutes = 0;    /*成员函数内可以直接访问私有成员*/
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int to1, to2;
    to1 = minutes + hours * 60;
    to2 = t.minutes + t.hours * 60;
    diff.minutes = (to1 - to2) % 60;
    diff.hours = (to1 - to2) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalMin = hours * mult * 60 + minutes * mult;
    result.minutes = totalMin % 60;
    result.hours = totalMin / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}