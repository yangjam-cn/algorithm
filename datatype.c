/*
 * @Author: youngjam
 * @Date: 2020-04-25 10:12:00
 * @LastEditTime: 2020-04-25 22:11:20
 * @Description: 自定义数据类型的函数实现
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */

#include<stdio.h>
#include"datatype.h"


/**
 * @description: 通过遍历数组将字符串 s1 的值复制到 s2
 * @input: s1、s2:字符数组的地址
 * @output: s1 复制到 s2
 */
void CopyString(char const s1[], char s2[])
{
    int i = 0;      // i 为数组下标

    /******--<遍历 s1 复制到 s2>--******/
    while (*(s1 + i) != '\0') {      // 字符串以 '\0' 结束
        *(s2 + i) = *(s1 + i);
        i++;
    }   // end while
    *(s2 + i) = '\0';       // 为 s2 添加终止标志

}   // end


/**
 * @description: 从键盘获取输入赋值给 element
 * @input: element: 变量地址
 * @output: 键盘输入赋给 element
 */
void GetData(DataType *const element)
{
    printf("please input the name:\t");
    scanf("%s", element->name);
    printf("please input the age:\t");
    scanf("%hd", &element->age);
    printf("please input the score:\t");
    scanf("%f", &element->score);

}   // end


/**
 * @description: 交换 e1 和 e2 的值
 * @input:  e1, e2:变量地址
 * @output: e1 和 e2 的之互换
 */
void SwapData(DataType *const e1, DataType *const e2)
{
    DataType temp;

    CopyData(e1, &temp);
    CopyData(e2, e1);
    CopyData(&temp, e2);

}   // end


/**
 * @description: 将 element 的值复制到 object
 * @input: element：原始对象， object：目标对象
 * @output: element 的值复制到 object
 */
void CopyData(DataType const *const element, DataType *const object)
{
    CopyString(element->name, object->name);
    object->age = element->age;
    object->score = element->score;

}   // end


void PrintData(DataType const *const element)
{
    printf("name = %s\tage = %d\tscore = %.2f\n", element->name, element->age, element->score);

}   // end


