/*
 * @Author: yangjam
 * @Date: 2020-05-31 19:45:58
 * @LastEditTime: 2020-05-31 21:06:54
 * @Environment: win10, gcc 8.1.0 & python 3.7.3
 * @Description: 主元消去法解线性方程组
 */ 
#include<stdio.h>
#include<math.h>
#define N 3
float A[N][N+1];
float X[N];


void findmain(int i)
{
    int j, k;
    float c;
    c = fabs(A[i][i]);
    k = i;
    for (j = i + 1; j < N; j++)
        if (fabs(A[j][i]) > c) {
            c = fabs(A[j][i]);
            k = j;
        }
    if (k != i)
        for (j = 0; j <= N; j++) {
            c = A[k][j];
            A[k][j] = A[i][j];
            A[i][j] = c;
        }
}

void divdmain(int i)
{
    int j;
    float c;
    c = A[i][i];
    A[i][i] = 1.0;
    for (j = i + 1; j <= N; j++)
        A[i][j] /= c;
}

void del(int i)
{
    int j, k;
    float c;
    for (j = 0; j < N; j++)
        if (j != i && A[j][i]) {
            c = A[j][i];
            A[j][i] = 0;
            for (k = i + 1; k <= N; k++)
                A[j][k] -= c * A[i][k];
        }
}

int main()
{
    int i, j;
    printf("\n请输入线性方程组的增广矩阵系数：\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
        printf("B[%d] = ", i + 1);
        scanf("%f", &A[i][N]);
    }
    getchar();
    for (i = 0; i < N; i++) {
        if (i < N - 1)
            findmain(i);
            divdmain(i);
            del(i);
    }
    for (i = 0; i < N; i++)
        X[i] = A[i][N];
    printf("\n线性方程组的解：\n");
    for (i = 0; i < N; i++)
        printf("X[%d] = %f", i + 1, X[i]);
    getchar();
    return 0;
}