/*
 * @Copyright: 版权说明
 * @File name: 文件名
 * @Description: 说明此程序文件的主要功能，与其它模块或函数的接口，输出值、取值范围、含义及参数间的控制、顺序、独立或依赖关系
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-12 14:55:41
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-12 15:49:30
 */ 
#include<stdio.h>
#include<stdlib.h>

/* 数据类型定义 */
typedef struct complex
{
    float real;
    float imaginary;
}complex;

/* 运算定义 */
complex create_comp(float x, float y);
complex add(complex a, complex b);
complex sub(complex a, complex b);
complex mul(complex a, complex b);
complex cdiv(complex a, complex b);
void print_comp(complex comp);

/* 运算实现 */
complex create_comp(float x, float y)
{
    complex comp;
    comp.real = x;
    comp.imaginary = y;
    return comp;
}

complex add(complex a, complex b)
{
    complex add;
    add.real = a.real + b.real;
    add.imaginary = a.imaginary + b.imaginary;
    return add;
}

complex sub(complex a, complex b)
{
    complex sub;
    sub.real = a.real - b.real;
    sub.imaginary = a.imaginary - b.imaginary;
    return sub;
}

complex mul(complex a, complex b)
{
    complex mul;
    mul.real = a.real * b.real - a.imaginary * b.imaginary;
    mul.imaginary = a.real * b.real + a.imaginary * b.imaginary;
    return mul;
}

complex cdiv(complex a, complex b)
{
    complex div;
    float sum;
    if (b.real == 0 && b.imaginary == 0)
    {
        printf("error: copmlex b == 0!\n");
        div = a;
    }
    else
    {
        sum = b.real * b.real + b.imaginary * b.imaginary;
        div.real = (a.real * b.real + a.imaginary * b.imaginary) / sum;
        div.imaginary = (a.imaginary * b.real - a.real * b. imaginary) / sum;
    }
    return div;
}

void print_comp(complex comp)
{
    if (comp.imaginary < 0)
    {
        printf("%.2f%.2fi\n", comp.real, comp.imaginary);
    }
    else
    {
        printf("%.2f+%.2fi\n", comp.real, comp.imaginary);
    }
}

int main()
{
    float x, y;
    complex a, b, res;
    printf("input the complex of a:\n");
    scanf("%f %f", &x, &y);
    a = create_comp(x, y);
    print_comp(a);
    printf("input the complex of b:\n");
    scanf("%f %f", &x, &y);
    b = create_comp(x, y);
    print_comp(b);
    res = add(a, b);
    print_comp(res);
    res = sub(a, b);
    print_comp(res);
    res = mul(a, b);
    print_comp(res);
    res = cdiv(a, b);
    print_comp(res);
    return 0;
}