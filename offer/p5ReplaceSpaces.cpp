/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p5ReplaceSpaces.cpp
 * @Description: 替换空格
 * 题目：实现一个函数，将字符串中的每个空格替换成“%20”
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 15:29:10
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 16:52:34
 */
#include <cstdio>
#include <cstring>


void replace_blank(char str[], int length)
{
    if (str == nullptr && length <= 0)
    {
        return;
    }

    int originalLength = 0;       /*输入字符串长度*/
    int numberOfBlank = 0;     /*空格数量*/

    int i = 0;                         /*字符数组下标*/
    while (str[i] != '\0')
    {
        originalLength++;      /*统计字符串长度*/
        
        if (str[i] == ' ')
        {
            numberOfBlank++;   /*统计空格数量*/
        }

        i++;
    }

    int newLength = originalLength + 2 * numberOfBlank;    /*新字符串的长度*/

    if (newLength > length)    /*新串的长度超过了字符数组的大小*/
    {
        return;
    }

    int indexOfOriginal = originalLength;    /*旧串的游标*/
    int indexOfNew = newLength;              /*新串的游标*/

    /*
     * 从后往前遍历字符数组，将原字符复制到新串中的对应位置
     * 当原字符都遍历完或者新串的的游标赶上原串的游标时，遍历结束
     */
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (' ' == str[indexOfOriginal])
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }

        indexOfOriginal--;
    }
}


/*============test code============*/
void test(const char *testName, char str[], int length, const char expected[])
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }

    replace_blank(str, length);

    if (expected == nullptr && str == nullptr)
    {
        printf("passed.\n");
    }
    else if (expected == nullptr && str != nullptr)
    {
        printf("failed.\n");
    }
    else if (0 == strcmp(str, expected))
    {
        printf("passed.\n");
    }
    else
    {
        printf("failed.\n");
    }
}

void test1(void)
{
    const int length = 100;

    char str[length] = "hello world";
    test("test1", str, length, "hello%20world");
}

void test2(void)
{
    const int length = 100;

    char str[length] = " helloworld";
    test("test2", str, length, "%20helloworld");
}

void test3(void)
{
    const int length = 100;

    char str[length] = "helloworld ";
    test("test3", str, length, "helloworld%20");
}

void test4(void)
{
    const int length = 100;

    char str[length] = "hello  world";
    test("test4", str, length, "hello%20%20world");
}

void test5(void)
{
    test("test5", nullptr, 0, nullptr);
}

void test6(void)
{
    const int length = 100;

    char str[length] = "";
    test("test6", str, length, "");
}

void test7(void)
{
    const int length = 100;

    char str[length] = "helloworld";
    test("test7", str, length, "helloworld");
}

void test8(void)
{
    const int length = 100;

    char str[length] = " ";
    test("test8", str, length, "%20");
}

void test9(void)
{
    const int length = 100;

    char str[length] = "   ";
    test("test9", str, length, "%20%20%20");
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    
    return 0;
}