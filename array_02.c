#include<stdio.h>
#define N 2
int main(void)
{
    int arr[N][N];
    printf("|x1 x2|\n");
    printf("|x3 x4|\n");
    for (int i = 0; i < N * N; i++) {
        printf("input the number x%d:", i + 1);
        scanf("%d", (int *)arr + i);
    }
    printf("|%d %d|\n", arr[0][0], arr[0][1]);
    printf("|%d %d|\n", arr[1][0], arr[1][1]);
    int result  = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    printf("det = %d\n", result);
    return 0;
}