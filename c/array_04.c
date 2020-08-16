// 矩阵相加
#include<stdio.h>
int main(void)
{
    int A[3][3] = {
        {1, 3, 5}, {7, 9, 11}, {13, 15, 17}
    };
    int B[3][3] = {
        {9, 8, 7}, {6, 5, 4}, {3, 2, 1}
    };
    int C[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            C[i][j] = A[i][j] + B[i][j];
    }
    printf("A + B = \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}