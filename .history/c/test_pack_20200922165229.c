/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 16:32:34
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 16:52:03
 */
#include <stdio.h>

#pragma pack(4)
struct Test
{
    char m_cElms[11];
    short m_sElm;
    int m_iElm;
};


int main(void)
{
    struct Test test;
    struct Test *tPtr = &test;
    printf("short = %d\n", sizeof(short));
    printf("size = %d\n", sizeof(struct Test));
    printf("start = %p, ++start = %p\n", &test, ++tPtr);
    return 0;
}