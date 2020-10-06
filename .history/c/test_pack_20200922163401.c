/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 16:32:34
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 16:34:01
 */
#include <stdio.h>

#pragma pack(2)
struct Test
{
    char chs[11];
};

int main(void)
{
    printf("size = %d", sizeof(struct Test));
    return 0;
}