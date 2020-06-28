/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: ptr_fun.c
 * @Description: 函数指针数组实例
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-06-28 18:32:33
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-28 18:57:59
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int a, int b);

void sub(int a, int b);

void my_div(int a, int b);

void mod(int a, int b);

int main()
{
    srand((unsigned int)time(NULL));

    void (*fun[4])(int a, int b);
    fun[0] = add;
    fun[1] = sub;
    fun[2] = my_div;
    fun[3] = mod;

    int a = rand() % 100;
    int b = rand() % 100;

    for (int i = 0; i < 4; i++)
    {
        fun[i](a, b);
    }
    return 0;
}

void add(int a, int b)
{
    printf("a + b = %d\n", a + b);
}

void sub(int a, int b)
{
    printf("a - b = %d\n", a - b);
}

void my_div(int a, int b)
{
    printf("a / b = %d\n", a / b);
}

void mod(int a, int b)
{
    printf("a %% b = %d\n", a % b);
}