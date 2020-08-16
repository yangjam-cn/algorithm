/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-09 12:57:56
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-09 13:56:42
 */
#include <stdio.h>

int test(int **ptr)
{
    printf("%p\t%p\t%d\t%d\n", ptr, ptr[0], **ptr, *(*ptr + 3));
}

int test2(int ptr[][3])
{
    printf("%p\t%p\t%d\n", ptr, ptr[0], ptr[0][3]);
    ptr[0][3] = 100;
}

int main(void)
{
    int a2[][3] = {{1, 2, 3}, {3, 4, 5}};
    // test(a2);    /*error, "a2" is int (*)[3]*/
    int *p1 = &a2[0][0];
    int **p2 = &p1; 
    test(p2);
    int **p3;
    *p3 = &a2[0][0];
    test2(a2);
    test(p3);
    return 0;
}