/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-30 09:34:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-30 09:48:40
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

void print_char(unsigned char *ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("ptr[%d] = 0x%x\t", i, *ptr);
    }
}


int main(void)
{
    return 0;
}