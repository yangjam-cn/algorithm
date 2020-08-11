/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 2020大疆c语言面试题
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 13:17:57
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 13:30:12
 */
#include <stdio.h>


#define mult(x, y) (x * y)


int main(void)
{
    int i = 3;
    int a;
    // char **b[5][6];    /*b是5*6二维二重字符指针数组名*/
    char (**b)[5][6];    /*b是二重指针，指向一个5*6的二维字符数组*/
    a = mult(i++, sizeof(b)  + 5);
    printf("%d", a);
    /*test*/
    printf("\n%d\t%d", sizeof(*b), sizeof(**b));    /*out:8 30*/
    /*****/
    return 0;
}
/*out = 725*/
/*a = i++ * sizeof(b) + 5*/
/*sizeof(b) = 8*5*6*/