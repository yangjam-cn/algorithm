/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 测试指定指针地址
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-20 15:35:27
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-20 15:49:43
 */
#include <stdio.h>

int main()
{
    int i = 0;
    printf("&i = 0x%p\n", &i);
    long long ptr_value = (long long)&i;
    int *ptr = (int *)ptr_value;
    *ptr = 0xaa;
    printf("0x%p\t0x%x\t0x%x\n", ptr, *ptr, i);
    ptr = (int *)0x61FE00;
    *ptr = 0xaabb;
    printf("0x%p\t0x%x", ptr, *ptr);
    return 0;
}