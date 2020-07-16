/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: callatz.c
 * @Description: 卡拉兹猜想
    * 对于任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。
    * 给定不超过1000的正整数n，简单数一下，需要多少步才能得到n=1？
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 15:16:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 15:33:49
 */ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    int number, cnt = 0;
    char flag = '\0';
    srand((unsigned int)time(NULL));
    while (flag != 'q')
    {
        number = rand() % 1000;
        cnt  = 0;
        printf("number = %d\n", number);
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number /= 2;
            }
            else
            {
                number = (3 * number + 1) / 2;
            }
            cnt++;
        }
        printf("cnt = %d\n", cnt);
        flag = getchar();
        getchar();
    }
    return 0;
}