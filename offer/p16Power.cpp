/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p16Power.cpp
 * @Description: 幂运算
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 08:06:19
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 09:14:30
 */
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;

const double INFS = 0.0000001;    /*定义常量无穷小*/
bool g_InvaildInput = false;           /*全局标志，输入是否合法*/
/*比较两个double类型数是否相等*/
bool equal(double num1, double num2);
/*计算数的幂*/
double power_with_unsigned_exponent(double base, unsigned int exponent);


/**
 * @Function: power
 * @Description: 计算数的幂
 * @Input: 
    * base：底数
    * exponent：幂指数
 * @Return: 
    * 当base==0.0，exponent < 0时，返回0.0，并标志输入非法
    * 输入合法返回幂运算结果
 */
double power(double base, int exponent)
{
    g_InvaildInput = false;

    /*当base==0，exp<0时，返回0，并标识输入非法*/
    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvaildInput = true;
        return 0.0;
    }

    /*将幂指数转化为无符号数*/
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }

    /*求幂运算结果*/
    double result = power_with_unsigned_exponent(base, absExponent);
    /*当幂指数为负，对幂运算结果求倒数*/
    if (exponent < 0)
    {
        result = 1.0 / result;
    }

    return result;
}


/**
 * @Function: 
 * @Description: 计算幂
 * @Input: 
    * base：double，底数
    * exponent：unsigned int，幂指数
 * @Return: 幂运算结果
 * @Others: 
 */
double power_with_unsigned_exponent(double base, unsigned int exponent)
{
    if (0 == exponent)
    {
        return 1;
    }
    if (1 == exponent)
    {
        return base;
    }

    double result = power_with_unsigned_exponent(base, exponent >> 1);
    result *= result;
    if (1 == (exponent & 0x01))
    {
        result *= base;
    }

    return result;
}


/**
 * @Function: 
 * @Description: 判断两个实数是否相等
 * @Input: 
    * num1：double，
    * num2：double，
 * @Return: 
    * 如果两者的差在指定范围内，则判定相等，返回true；否则返回false
 * @Others: 其它说明
 */
bool equal(double num1, double num2)
{
    if ((num1 - num2 < INFS) && (num1 - num2) > -INFS)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*============test code============*/
void test(const char *testName, double base, int exponent, double expectedResult, 
    bool expectedFlag)
{
    double result = power(base, exponent);
    if (equal(result, expectedResult) && g_InvaildInput == expectedFlag)
    {
        cout << testName << " passed." << endl;
    }
    else
    {
        cout << testName << " failed." << endl;
    }
}

int main(void)
{
    test("test1", 2, 3, 8, false);

    test("test2", -2, 3, -8, false);

    test("test3", 2, -3, 0.125, false);

    test("test4", 2, 0, 1, false);

    test("test5", 0, 0, 1, false);

    test("test6", 0, 4, 0, false);

    test("test6", 0, -4, 0, true);

    return 0;
}
