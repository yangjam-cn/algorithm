/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-11 20:05:32
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-11 20:16:14
 */
#include<iostream>
#include <stdio.h>
int main(void)
{
    int a = 0x12345678;
    int *p = &a;
    // *p = 0x12345678;
    printf("%p\n", (char *)p);
    return 0;
}