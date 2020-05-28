#include<stdio.h>
int main(void)
{
    int num[2][3][3] = {
        {
            {33, 45, 67}, {23, 71, 66}, {55, 38, 66}
        },
        {
            {21, 9, 15}, {38, 69, 18}, {90, 101, 89}
        }
    };
    int value = num[0][0][0];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (value >= num[i][j][k]) {
                    value = num[i][j][k];
                    printf("%d\t", value);
                }
            }
        }
    }
    return 0;
}
