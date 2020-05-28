/*
 * @Author: youngjam
 * @Date: 2020-04-17 22:38:50
 * @LastEditTime: 2020-04-17 23:22:15
 * @Description: 矩阵乘法
 * @FilePath: /DataStructure/alg1_4.c
 * @无味人间，寡欲清欢！
 */
/*
 *2020年 04月 17日 星期五 22:39:07 CST
 *algothem:矩阵乘法
 *model:两个n维方阵相乘
 *input:一个正整数n，二维数字数组A和B，其索引值为0～n-1
 *output:A和B相乘得到的n维方阵C
*/
/* 伪代码描述 */
/*
void matrixmult(int n, number const A[][], number const B[][], number C[][])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k]*b[k][j]
}
*/
/* 代码实现 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 4

void matrix_mult(int const A[N][N], int const B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }
}

void print(int s[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t", s[i][j]);
        printf("\n");
    }
}

int main(void)
{
    srand((int)time(0));
    int A[N][N] = {0};
    int B[N][N] = {0};
    int C[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 20 - 10;
            B[i][j] = rand() % 10 - 5;
        }
    }
    print(A);
    print(B);
    matrix_mult(A, B, C);
    return 0;
}