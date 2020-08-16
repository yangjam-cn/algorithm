// 矩阵转置
#include<stdio.h>
#include<malloc.h>

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void transpose(int *arrA, int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            swap(&arrA[i*N+j], &arrA[j*N+i]);
        }
    }
}

void print_matrix(int *arrA, int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t", arrA[i*N+j]);
        printf("\n");
    }
}

int main(void)
{
    int N;
    int *arrA/*arrB*/;
    printf("input the dimsion of matrix: ");
    scanf("%d", &N);
    arrA = (int *)malloc(sizeof(int) * N * N);
    // arrB = (int *)malloc(sizeof(int) * N * N);
    for (int i = 0; i < N * N; i++) {
        arrA[i] = i;
    }
    printf("original matrix:\n");
    print_matrix(arrA, N);
    transpose(arrA, N);
    printf("transpose matrix:\n");
    print_matrix(arrA, N);
    free(arrA);
    return 0;
}