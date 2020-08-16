/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-16 11:48:22
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-16 12:19:51
 */
#include <stdio.h>

void test(int a)
{
    printf("**%d**\n", a);
}

int main(void)
{
    int number = 12;
    int array[] = {1, 2, 3, 4, 5};

    int *pInt = &number;                           /*int变量指针*/

    int **ppInt = &pInt;                            /*int *变量指针*/

    int *pArrayInt[] = {pInt, &array[4]};    /*int指针数组*/

    int (*pIntArray)[] = &array;                 /*int数组指针*/

    void (*pFun)(int) = test;                       /*函数指针*/

    void (*pFunArray[])(int) = {test};         /*函数指针数组*/

    pFun((*pIntArray)[0]);

    pFunArray[0](*pArrayInt[1]);

    return 0;
}