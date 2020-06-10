/*
 * @Copyright: 《ARM常用算法》
 * @File name: day_6_1.c
 * @Description: 折线插值
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-01 21:39:08
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-01 21:59:08
 */ 
#include<stdio.h>
#define NUM 10
float interval = 10.0;
float start_temp = 0.0;
float end_temp = 100.0;
int adc_val[NUM + 1] = {86, 376, 687, 1021, 1379, 1760, 2164, \
                      2592, 3043, 3515, 4008};

float fitting_straight(int val)
{
    int cnt;

    if (val < adc_val[0])
    {
        return start_temp;
    }
    if (val > adc_val[NUM])
    { 
        return end_temp;
    }

    for (cnt = 0; cnt < NUM; cnt++)
    {
        if (val < adc_val[cnt + 1])
        {
            break;
        }
    }

    return (interval * cnt + interval * (val - adc_val[cnt])
        / (adc_val[cnt + 1] - adc_val[cnt]));
}

void main()
{
    int val;
    float result;
    while(1)
    {
       printf("\n输入A/D转换结果：");
       scanf("%d", &val);

       if (val == 0)
       {
           break;
       }

       result = fitting_straight(val);
       printf("\n对应的温度为: %2.2f^C\n", result);
    }
}
