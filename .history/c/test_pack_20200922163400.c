#include <stdio.h>

#pragma pack(2)
struct Test
{
    char chs[11];
};

int main(void)
{
    printf("size = %d", sizeof(struct Test));
    return 0;
}