/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:37:34
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 14:16:19
 */
#include <iostream>

#include "GetMin.cpp"

int main(void)
{
    GetMin<int> test;
    using namespace std;

    int arr[6] = {3, 2, 2, 4, 1, 5};
    for (int elem : arr)
        test.push(elem);
}