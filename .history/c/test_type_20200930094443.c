/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-30 09:34:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-30 09:44:43
 */
#include <stdio.h>

#define cSize sizeof(char)
#define ucSize sizeof(unsigned char)
#define sSize sizeof(short)
#define usSize sizeof(unsigned short)
#define iSize sizeof(int)
#define uiSize sizeof(unsigned int)
#define lSize sizeof(long)
#define ulSize sizeof(unsigned long)
#define fSize sizeof(float)
#define dSize sizeof(double)

int main(void)
{
    printf("short = %d\n", sSize);
    printf("long = %d\n", lSize);
    printf("float = %d\n", fSize);
    printf("double = %d\n", dSize);
    return 0;
}