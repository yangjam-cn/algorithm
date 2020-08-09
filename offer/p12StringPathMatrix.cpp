/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p12StringPathMatrix.cpp
 * @Description: 矩阵中的路径
 * 题目：设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵
 * 中的任意一格开始，每一步可以在矩阵中向上、下、左、右移动一格。如果一条路径经过了矩阵的某一格，
 * 那么该路径不能再次进入该格子。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 19:29:29
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-08 20:42:58
 */
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

bool has_path_core(const char *matrix, int rows, int cols, int row, int col, const char *str,
    int &pathLength, bool *visited);


bool has_path(const char *matrix, int rows, int cols, const char *str)
{
    if (nullptr == matrix || rows < 1 || cols < 1 || nullptr == str)
    {
        return false;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (has_path_core(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

bool has_path_core(const char *matrix, int rows, int cols, int row, int col, const char *str,
    int &pathLength, bool *visited)
{
    if ('\0' == str[pathLength])
    {
        return true;
    }

    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols 
        && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = has_path_core(matrix, rows, cols, row, col - 1, str, pathLength, visited)
            || has_path_core(matrix, rows, cols, row - 1, col, str, pathLength, visited)
            || has_path_core(matrix, rows, cols, row, col + 1, str, pathLength, visited)
            || has_path_core(matrix, rows, cols, row + 1, col, str, pathLength, visited);
        
        if (!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}


/*===========test code============*/
void test(const char *testName, const char *matrix, int rows, int cols, const char *str, 
    bool expected)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }
    
    if (has_path(matrix, rows, cols, str) == expected)
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
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "BFCE";

    test("test1", matrix, 3, 4, str, true);
}

void test2()
{
    const char *matrix = "ABCESFCSADEE";
    const char *str = "SEE";

    test("test2", matrix, 3, 4, str, true);
}

void test3()
{
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "ABFB";

    test("test3", matrix, 3, 4, str, false);
}

void test4()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SLHECCEIDEJFGGFIE";

    test("test4", matrix, 5, 8, str, true);
}

void test5()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEEJIGOEM";

    test("test5", matrix, 5, 8, str, false);
}

void test6()
{
    const char *matrix = "A";
    const char *str = "A";

    test("test6", matrix, 1, 1, str, true);
}

void test7()
{
    const char *matrix = "A";
    const char *str = "B";

    test("test7", matrix, 1, 1, str, false);
}

void test8()
{
    test("test8", nullptr, 0, 0, nullptr, false);
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