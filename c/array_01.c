#include<stdio.h>
void main(void)
{
    int Score[5] = {87, 66, 90, 65, 70};
    int Total_Score = 0;
    for (int i = 0; i < 5; i++) {
        printf("第%d位同学的分数: %d\n", i, Score[i]);
        Total_Score += Score[i];
    }
    printf("---------------------------------\n");
    printf("5位同学的总分数: %d\n", Total_Score);
}