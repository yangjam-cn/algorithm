/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p4FindPartiallySprtedMatrix.cpp
 * @Description: 二维数组中的查找
 * 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下的顺序
 * 排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 13:56:17
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 14:33:34
 */
#include <cstdio>


/**
 * @Function: 在有序二维数组中查找指定的值
 * @Input: 
    * matrix->数组首元素地址
    * rows->矩阵行数
    * cloumns->矩阵列数
    * number->待查找的值
 * @Return: 
    * true->查找的值在数组中
    * false->查找的值不在数组中 
 * @Others: 
 */
bool find(int *matrix, int rows, int cloumns, int number)
{
    bool found = false;

    if (matrix != nullptr && rows > 0 && cloumns > 0)    /*输入合法性检查*/
    {
        int cloumn = 0;        /*第一列*/
        int row = rows - 1;    /*最后一行*/

        /*
         * 从左下角向右上方遍历
         * 左下角为每一行最小，每一列最大元素，每次判断可以排除某一行或某一列
         * 时间复杂度为O(rows+cloumns)
         */
        while (cloumn < cloumns && row >= 0)
        {
            if (matrix[row * cloumns + cloumn] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * cloumns + cloumn] < number)
            {
                cloumn++;
            }
            else
            {
                row--;
            }
        }    /*end while*/
    }
    return found;
}


/*============test code============*/
void test(char const *testName, int *matrix, int rows, int cloumns, 
    int number, bool expected)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }

    bool result = find(matrix, rows, cloumns, number);

    if (result == expected)
    {
        printf("Passed.\n");
    }
    else
    {
        printf("FAILED.\n");
    }
}


void test1()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test1", (int *)matrix, 4, 4, 7, true);
}

void test2()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test2", (int *)matrix, 4, 4, 5, false);
}

void test3()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test3", (int *)matrix, 4, 4, 1, true);
}

void test4()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test4", (int *)matrix, 4, 4, 15, true);
}

void test5()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test5", (int *)matrix, 4, 4, 0, false);
}

void test6()
{
    int matrix[][4] = {{1, 2, 8, 9},
                       {2, 4, 9, 12},
                       {4, 7, 10, 13},
                       {6, 8, 11, 15}};
    test("test6", (int *)matrix, 4, 4, 16, false);
}

void test7()
{
    test("test7", nullptr, 0, 0, 16, false);
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
}