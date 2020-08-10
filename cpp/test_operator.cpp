/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: test_operator.cpp
 * @Description: 运算符重载
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-10 18:53:47
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-10 19:44:00
 */

/*
 * 重载限制
 * 1. 运算符必须至少有一个操作数是用户定义类型
 * 2. 不能违反原来的句法规则
 * 3. 不能创建新的运算符
 * 4. 不能重载部分运算符
 * 5. =、（）、[]、->只能通过成员函数进行重载
 */

/*
 * 友元函数
 * 为非成员函数赋予访问类私有成员的权限
 */

#include <iostream>

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        Time operator+(const Time &t) const;
        Time operator-(const Time &t) const;
        /*
         * 成员函数参数较友元函数版本参数少一个，其中一个参数通过this隐式传递给调用对象
         * 当成员函数和友元函数原型一致时，运算符定义时只能有一个版本
         */
        Time operator*(double n) const;
        friend Time operator*(double m, const Time &t);
        // {
        //     return t * m;
        // }
        friend std::ostream & operator<<(std::ostream &os, const Time &t);
};

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}


/*
 * 函数后const标识不改变数据成员的成员函数，一旦改变，编译报错
 * 1. 非静态成员函数才能添加const
 * 2. 表示成员函数隐含传入的this指针为const指针
 * 3. const成员函数可以被const和非const成员调用，而非const成员只能被非const对象调用
 */
Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes = sum.minutes % 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1, tot2;
    tot2 = t.minutes + 60 * t.hours;
    tot1 = minutes + 60 * hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalMinutes = hours * mult * 60 + minutes * mult;
    result.minutes = totalMinutes % 60;
    result.hours = totalMinutes / 60;
    return result;
}

Time operator*(double mult, const Time &t)
{
    return t * mult;
}

std::ostream & operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}


int main(void)
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << temp << endl;
    temp = aida - tosca;
    cout << temp << endl;
    temp = aida * 1.17;
    cout << temp << endl;
    temp = 1.5 * tosca;
    cout << temp << endl;

    return 0;
}