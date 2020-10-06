/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 08:45:47
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 09:03:38
 */
// #include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Enter target distance (q to quit):";
    while (cin >> target)
    {
        cout << "Enter step length:";
        if (!(cin >> dstep))
            break;
        
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }

        cout << "After " << steps << "steps, the subject has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << "or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance(q to quit):";
    }
    cout << "Bye!\n";
    return 0;
}