/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-30 09:34:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-30 10:06:01
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define cSize  sizeof(char)
#define ucSize sizeof(unsigned char)
#define sSize  sizeof(short)
#define usSize sizeof(unsigned short)
#define iSize  sizeof(int)
#define uiSize sizeof(unsigned int)
#define lSize  sizeof(long)
#define ulSize sizeof(unsigned long)
#define fSize  sizeof(float)
#define dSize  sizeof(double)

void print_Byte(unsigned char *ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("ptr[0x%p] = 0x%x\t", ptr, *ptr);
        ++ptr;
    }
    putchar('\n');
}


int main(void)
{
    char i_1Data = CHAR_MIN;
    unsigned char uc_1Data = UCHAR_MAX;
    short s_2Data = SHRT_MIN;
    unsigned short us_2Data = USHRT_MAX;
    int i_4Data = INT_MIN;
    unsigned int ui_4Data = UINT_MAX;
    long l_4Data = LONG_MIN;
    unsigned long ul_4Data = ULLONG_MAX;
    float f_4Data = FLT_MIN;
    double d_8Data = DBL_MIN;

    print_Byte((unsigned char *)&(&c_1Data), iSize);

    return 0;
}