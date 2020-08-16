/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-13 16:50:24
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-13 17:02:48
 */
#include <stdio.h>

int main(void)
{
    int a[10] = {0};
    int *ptr1 = (int *)a;
    int (*ptr2)[10] = &a;

    printf ("%p\t%p\t%p\t%p\n", a, &a + 1, ++ptr1, ++ptr2);
    printf("%d\t%d\t%d\n", sizeof(ptr1), sizeof(ptr2), sizeof(a));
    return 0;
}

/*a 数组名，数组首元素地址；a + i, a中第i号元素地址*/
/*&a，数组地址*/
/*++a，a++无效表达式*/
/*sizeof(a)数组大小，sizeof(ptr1)=sizeof(ptr2)指针大小*/