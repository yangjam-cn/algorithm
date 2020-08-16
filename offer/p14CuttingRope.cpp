/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p14CuttingRope.cpp
 * @Description: 剪绳子
 * 题目：给一根长度为n的绳子，剪成m段(m,n均为整数，n>1,m>= 1)。每段绳子的长度记为k[0],k[1],
 * ...,k[m]，求可能的最大乘积。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-09 16:04:49
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-09 16:16:07
 */
#include <iostream>
#include <cmath>

int max_product_after_cutting_dynamic(int length)
{
    if (length < 2)
    {
        return 0;
    }
    if (2 == length)
    {
        return 1;
    }
    if (3 == length)
    {
        return 2;
    }

    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for (int i = 4; i <= length; ++i)
    {
        max = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            int product = products[j] * products[i - j];
            if (max < product)
            {
                max = product;
            }

            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;
}