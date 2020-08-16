#include<stdio.h>
int main(void)
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int const *icp = &arr[0][0];
    int *const ipc = &arr[0][0];
    // int const * const icpc = &arr[0][0];
    icp = &arr[0][1];
    /*
    *icp = 12;                   //error: *icp is read-only//指针可变，指向的数据不可变
    ipc = &arr[0][1];      //error: ipc is read-only//指针不可变，内容可变
    */
    *ipc = 12;
    /*
    icpc = &arr[0][1];  //error: icpc is read-only
    *icpc = 12;              //error: *icpc is read-only
    */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            printf("arr[%d][%d] = %d, address = %p\n", i, j, arr[i][j], &arr[i][j]);
    }
    printf("arr = %p\n", arr);
    printf("arr[0] = %p\n", arr[0]);
    printf("arr[1] = %p\n", arr[1]);
    return 0;
}