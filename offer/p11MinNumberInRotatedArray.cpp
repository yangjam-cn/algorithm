/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 15:10:33
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-08 15:39:18
 */
#include <cstdio>
#include <stdexcept>

int min_in_order(int *numbers, int indexStart, int indexEnd);

int min(int *numbers, int length)
{
    if (numbers == nullptr || length < 0)
    {
        throw std::invalid_argument("Invalid parameters.");
    }

    int indexStart = 0;
    int indexEnd = length - 1;
    int indexMid = indexStart;
    while (numbers[indexStart] >= numbers[indexEnd])
    {
        if (indexEnd - indexStart == 1)
        {
            indexMid = indexEnd;
            break;
        }

        indexMid = (indexStart + indexEnd) / 2;
        if (numbers[indexStart] == numbers[indexEnd] 
            && numbers[indexMid] == numbers[indexStart])
        {
            return min_in_order(numbers, indexStart, indexEnd);
        }

        if (numbers[indexMid] >= numbers[indexStart])
        {
            indexStart = indexMid;
        }
        else if (numbers[indexMid] <= numbers[indexEnd])
        {
            indexEnd = indexMid;
        }
    }

    return numbers[indexMid];
}

int min_in_order(int *numbers, int indexStart, int indexEnd)
{
    int result = numbers[indexStart];
    for (int i = indexStart + 1; i <= indexEnd; i++)
    {
        if (result > numbers[i])
        {
            result = numbers[i];
        }
    }

    return result;
}


/*===========test code============*/
void test(int *numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = min(numbers, length);

        for (int i = 0; i < length; ++i)
        {
            printf("%d ", numbers[i]);
        }

        if (result == expected)
        {
            printf("\npassed.\n");
        }
        else
        {
            printf("failed.\n");
        }
    }
    catch(...)
    {
        if (numbers == nullptr)
        {
            printf("test passed.\n");
        }
        else
        {
            printf("test failed.\n");
        }
    }
}

int main(void)
{
    int array1[] = {3, 4, 5, 1, 2};
    test(array1, sizeof(array1) / sizeof(int), 1);

    int arr2[] = {3, 4, 5, 1, 1, 2};
    test(arr2, sizeof(arr2) / sizeof(int), 1);

    int arr3[] = {3, 4, 5, 1, 2, 2};
    test(arr3, sizeof(arr3) / sizeof(int), 1);

    int arr4[] = {1, 0, 1, 1, 1};
    test(arr4, sizeof(arr4) / sizeof(int), 0);

    int arr5[] = {1, 2, 3, 4, 5};
    test(arr5, sizeof(arr5) / sizeof(int), 1);

    int arr6[] = {2};
    test(arr6, sizeof(arr6) / sizeof(int), 2);

    test(nullptr, 0, 0);

    return 0;
}
