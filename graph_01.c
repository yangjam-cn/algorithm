//  邻接矩阵构造无向图
#include<stdio.h>
int main()
{
    int arr[6][6] = {0};
    int data[10][2] = {
        {1, 2}, {2, 1}, {1, 5}, {5,1}, {2, 3}, {3, 2}, {2, 4}, {4, 2}, {3, 4}, {4,3}
    };
    int tempi = 0, tempj = 0;
    for (int i = 0; i < 10; i++) {
        tempi = data[i][0];
        tempj = data[i][1];
        arr[tempi][tempj] = 1;
    }
    printf("undirected graph matrix:\n");
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}