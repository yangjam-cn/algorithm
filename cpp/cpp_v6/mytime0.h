/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-16 21:01:20
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-16 21:24:47
 */
#ifndef MYTIME0_H
#define MYTIME0_H

class Time
{
    /*私有成员*/
    private:
        int hours;
        int minutes;
    /*公有成员*/
    public:
        Time();                                                  /*默认构造函数*/
        Time(int h, int m = 0);                            /*构造函数*/
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        const Time Sum(const Time &t) const;
        void Show() const;
};
#endif