/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-13 20:49:43
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-13 22:03:18
 */
#include <iostream>
#include <cstring>

using namespace std;


char *calculate_string_mul_char(char *num1, char num, char *resLast)
{
    if (num == '0')
    {
        *(--resLast) += '0';
        return resLast;
    }

    int len = strlen(num1);
    int carryValue = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        int mul1 = num1[i] - '0';
        int mul2 = num - '0';
        int pre = 0;

        if (*(--resLast) != '\0')
            pre = *resLast - '0';
        
        *(resLast) = (char)((mul1 * mul2 + carryValue + pre) % 10 + '0');
        carryValue = (mul1 * mul2 + pre + carryValue) / 10;
    }
    return resLast;
}

int main(void)
{
    char num1[10];
    char num2[10];
    cin >> num1;
    cin >> num2;
    int len1 = strlen(num1), len2 = strlen(num2);
    char *res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    for (int i = 0; i <= len1 + len2; i++)
        res[i] = '\0';
    res = res + len1 + len2;
    
    char *resFirst;
    for (int i = strlen(num2) - 1, j = 0; i >= 0; --i, ++j)
    {
        resFirst = calculate_string_mul_char(num1, num2[i], res - j);
    }
    cout << resFirst << endl;
    res = res - len1 - len2;
    free(res);
    return 0;
}