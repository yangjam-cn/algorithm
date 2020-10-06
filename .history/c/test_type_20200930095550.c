/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-30 09:34:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-30 09:55:50
 */
#include <stdio.h>
#include <limits.h>

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

void print_Byte(unsigned char *ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("ptr[0x%p] = 0x%x\t", ptr, *ptr);
        ++ptr;
    }
}


int main(void)
{
    char i_1Data = 'a';
    unsigned char uc_1Data = 'a';
    int i_4Data = 255;
    print_Byte((unsigned char *)&(i_4Data), iSize);
    return 0;
}