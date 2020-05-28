//  邻接矩阵构建有向图
#include<stdio.h>
int main()
{
    int arr[6][6] = {0};
    int data[6][2] = {
        {1, 2}, {2, 3}, {2, 4}, {2, 1}, {4, 1}, {4, 2}
    };
    int tempi = 0, tempj = 0;
    for (int i = 0; i < 6; i++) {
        tempi = data[i][0];
        tempj = data[i][1];
        arr[tempi][tempj] = 1;
    }
    printf("directed graph matrix:\n");
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}