//  稀疏矩阵
#include<stdio.h>
#include<malloc.h>

// int count(int **arr, int m, int n)
// {
//     int count = 0;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (arr[i][j] != 0)
//                 count++;
//         }
//     }
//     return count;
// }

void compression(int **arrA, int **arrB, int m, int n)
{
    int temp = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arrA[i][j] != 0) {
                arrB[temp][0] = i;
                arrB[temp][1] = j;
                arrB[temp][2] = arrA[i][j];
                temp++;
            }
        }
    }
}

void print_matrix(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) 
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}

int main()
{
    int sparse[6][6] = {
        {15, 0, 0, 22, 0, -15}, {0, 11, 3, 0, 0, 0}, {0, 0, 0, -6, 0, 0},\
        {0, 0, 0, 0, 0, 0}, {91, 0, 0, 0, 0, 0}, {0, 0, 0, 28, 0, 0}
    };
    int NonZero = 0;
    int **Sparse = (int **)malloc(sizeof(int*) * 6);
    for (int i = 0; i < 6; i++)
        Sparse[i] = (int *)malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            Sparse[i][j] = sparse[i][j];
            if (sparse[i][j] != 0)
                NonZero++;
        }
    }
    print_matrix(Sparse, 6, 6);
    // NonZero = count(Sparse, 6, 6);
    int **comp = (int **)malloc(sizeof(int *) * (NonZero+1));
    for (int i = 0; i <= NonZero; i++)
        comp[i] = (int *)malloc(sizeof(int) * 3);
    comp[0][0] = 6;
    comp[0][1] = 6;
    comp[0][2] = NonZero;
    compression(Sparse, comp, 6, 6);
    print_matrix(comp, NonZero + 1, 3);
    for (int i = 0; i <= NonZero; i++)
        free(comp[i]);
    free(comp);
    for (int i = 0; i < 6; i++)
        free(Sparse[i]);
    free(Sparse);
    return 0;
}