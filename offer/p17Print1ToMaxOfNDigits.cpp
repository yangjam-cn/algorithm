/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-11 09:41:35
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-11 10:14:22
 */
#include <iostream>
#include <memory>
#include <cstring>

void print_number(char *number);
bool increment(char *number);
void print_1_to_max_of_n_digits_recursively(char *number, int length, int index);


/*============way 1============*/
void print_1_to_max_of_n_digits_1(int n)
{
    if (0 >= n)
    {
        return;
    }

    char *number = new char [n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increment(number))
    {
        print_number(number);
    }

    delete [] number;
}


bool increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
        {
            ++nSum;
        }

        if (nSum >= 10)
        {
            if (0 == i)
            {
                isOverflow = true;
            }
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}


/*============way 2============*/
void print_1_to_max_of_n_digits_2(int n)
{
    if (n <= 0)
    {
        return ;
    }

    char *number = new char [n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        print_1_to_max_of_n_digits_recursively(number, n, 0);
    }

    delete [] number;
}

void print_1_to_max_of_n_digits_recursively(char *number, int length, int index)
{
    if (index == length - 1)
    {
        print_number(number);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        number[index + 1] = i + '0';
        print_1_to_max_of_n_digits_recursively(number, length, index + 1);
    }
}


/*============public function============*/
void print_number(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
        {
            isBeginning0 = false;
        }

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}


/*============test code============*/
void test(int n)
{
    printf("test for %d begins:\n", n);

    print_1_to_max_of_n_digits_1(n);
    print_1_to_max_of_n_digits_2(n);

    printf("\ntest for %d ends.\n", n);
}

int main(void)
{
    test(1);
    test(2);
    test(3);
    test(0);
    test(-1);
    return 0;
}