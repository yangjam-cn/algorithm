// 矩阵相乘
#include<stdio.h>
#include<malloc.h>

void Matrix_Multiply(int **arrA, int **arrB, int (*arrC)[2], int M, int N, int P)
{
    if (M <= 0 || N <= 0 || P <= 0) {
        printf("error: dimsion must greater than 0!\n");
        return;
    }
    int Temp = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            Temp = 0;
            for (int k = 0; k < N; k++)
                Temp += arrA[i][k] * arrB[k][j];
            arrC[i][j] = Temp;
        }
    }
}

int **Create_2matrix(int M, int N)
{
    int **arr = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
        arr[i] = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("a%d%d = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

void Free_2matrix(int **arr, int N)
{
    for (int i = 0; i < N; i++)
        free(arr[i]);
    free(arr);
}

int main(void)
{
    int M, N, P;
    printf("input the dimsion of matrix: M, N, P\n");
    scanf("%d %d %d", &M, &N, &P);
    int **A, **B;
    A = Create_2matrix(M, N);
    B = Create_2matrix(N, P);
    int (*C)[P] = (int(*)[P])malloc(sizeof(int) * M * P);
    Matrix_Multiply(A, B, C, M, N, P);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) 
            printf("%d\t", C[i][j]);
        printf("\n");
    }
    Free_2matrix(A, N);
    Free_2matrix(B, P);
    free(C);
    return 0;
}