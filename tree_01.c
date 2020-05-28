// 一维数组存储二叉树
#include<stdio.h>

void btree_create(int *btree, int *data, int length)
{
    for (int i = 0; i < length; i++) {
        int level = 0;
        while (btree[level] != 0) {
            if (data[i] > btree[level])
                level = 2 * level + 2;
            else 
                level = 2 * level + 1;
        }
        btree[level] = data[i];
    }
}

void print_array(int *ptr, int length)
{
    for (int i = 0; i < length; i++)
        printf("[%d]  ", ptr[i]);
    printf("\n");
}

int main(void)
{
    int length = 9;
    int data[9] = {6, 3, 5, 4, 7, 8, 9, 2, 1};
    int btree[15] = {0};
    btree_create(btree, data, length);
    print_array(data, 9);
    print_array(btree, 15);
    return 0;
}