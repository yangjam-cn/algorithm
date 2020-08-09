/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p13RobotMove.cpp
 * @Description: 机器人的运动范围
 * 题目：地上有m行n列的方格。一个机器人从(0,0)的格子移动，它每次可以上、下、左、右移动一格，但不能
 * 进入行坐标和列坐标的数位之和大于k的格子。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 21:13:45
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-09 12:10:24
 */
#include <cstdio>

int moving_count_core(int threshold, int rows, int cols, int row, int col, bool *visited);
bool check(int threshold, int rows, int cols, int row, int col, bool *visited);
int get_digit_sum(int number);

int moving_count(int threshold, int rows, int cols)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
    {
        visited[i] = false;
    }

    int count = moving_count_core(threshold, rows, cols, 0, 0, visited);

    delete[] visited;

    return count;
}

int moving_count_core(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;

        count = 1 + moving_count_core(threshold, rows, cols, row - 1, col, visited)
            + moving_count_core(threshold, rows, cols, row, col - 1, visited)
            + moving_count_core(threshold, rows, cols, row + 1, col, visited)
            + moving_count_core(threshold, rows, cols, row, col + 1, visited);
    }

    return count;
}


bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols 
        && get_digit_sum(row) + get_digit_sum(col) <= threshold
        && !visited[row * cols + col])
    {
        return true;
    }
    return false;
}

int get_digit_sum(int number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /=  10;
    }

    return sum;
}


/*============test code============*/
void test(const char *testName, int threshold, int rows, int cols, int expected)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }

    if (expected == moving_count(threshold, rows, cols))
    {
        printf("passed.\n");
    }
    else
    {
        printf("failed.\n");
    }
}

void test1()
{
    test("test1", 5, 10, 10, 21);
}

void test2()
{
    test("test2", 15, 20, 20, 359);
}

void test3()
{
    test("test3", 10, 1, 100, 29);
}

void test4()
{
    test("test4", 10, 1, 10, 10);
}

void test5()
{
    test("test5", 15, 100, 1, 79);
}

void test6()
{
    test("test6", 15, 10, 1, 10);
}

void test7()
{
    test("test7", 0, 1, 1, 1);
}

void test8()
{
    test("test8", -10, 10, 10, 0);
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

    return 0;
}

