/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-20 15:35:27
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-20 15:41:00
 */
#include <stdio.h>

int main()
{
    int i = 0;
    long long ptr_value = (int)&i;
    int *ptr = (int *)ptr_value;
    *ptr = 0xaa;
    printf("%p\t%x", ptr, *ptr);
    return 0;
}