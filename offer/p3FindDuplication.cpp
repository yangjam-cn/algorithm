/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p3FindDuplication.cpp
 * @Description: 找出数组中的重复数字
 * 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内，数组中某些数字是重复的，但不知道有
 * 几个数字重复了，也不知道每个数字重复了几次，找出数组中任意一个重复的数字。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 09:17:11
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 13:16:10
 */
#include <cstdio>

bool duplicate(int numbers[], int length, int *duplication)
{
    if ((numbers == nullptr) || (length < 0))
    {
        return false;
    }

    for (int i = 0; i < length; ++i)
    {
        if ((numbers[i] < 0) || (numbers[i] > (length - 1)))
        {
            return false;
        }
    }

    for (int i = 0; i < length; ++i)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}


/*==========测试代码==========*/
bool contains(int array[], int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == number)
        {
            return true;
        }
    }
    
    return false;
}

void test(char const *testName, int numbers[], int lengthNumbers, 
    int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if (validArgument == validInput)
    {
        if (validInput)
        {
            if (contains(expected, expectedExpected, duplication))
            {
                printf("Passed.\n");
            }
            else
            {
                printf("FAILED.\n");
            }
        }
        else
        {
            printf("Passed.\n");
        }
    }
    else
    {
        printf("FAILED.\n");
    }
}

void test1()
{
    int numbers[] = {2, 1, 3, 1, 4};
    int duplications[] = {1};
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications,
        sizeof(duplications) / sizeof(int), true);
}

void test2()
{
    int numbers[] = {2, 4, 3, 1, 4};
    int duplications[] = {4};
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications,
        sizeof(duplications) / sizeof(int), true);
}

void test3()
{
    int numbers[] = {2, 4, 2, 1, 4};
    int duplications[] = {2, 4};
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications,
        sizeof(duplications) / sizeof(int), true);
}

void test4()
{
    int numbers[] = {2, 1, 3, 0, 4};
    int duplications[] = {-1};
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications,
        sizeof(duplications) / sizeof(int), false);
}

void test5()
{
    int numbers[] = {2, 1, 3, 5, 4};
    int duplications[] = {-1};
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications,
        sizeof(duplications) / sizeof(int), false);
}

void test6()
{
    int *numbers = nullptr;
    int duplications[] = {-1};
    test("Test6", numbers, 0, duplications, 
        sizeof(duplications) / sizeof(int), false);
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}


/*哈希表的思想，将value映射为新数组的下标，时间复杂度O(n),空间复杂度O(n)*/
// int findRepeatNumber(int* nums, int numsSize){
//     /*申请和输入数组同样大小的数组，并初始化为0*/
//     int *find = (int *)calloc(numsSize, sizeof(int));

//     int i = -1;
//     /*
//      * 遍历数组，将nums[i]的值value映射为find的下标，当value出现时则对find[value]自加；
//      * find所有值初始化为0；
//      * 若value未遍历过，则find[value]=0，利用find[value]统计value的出现次数
//      * 若value遍历过，则find[value]>0，再次遍历到value即可确定value重复
//      */
//     while (i++ < numsSize) {
//         if (find[nums[i]]) {
//             free(find);
//             return nums[i];
//         }
//         else
//             find[nums[i]]++;
//     }
//     free(find);
//     return -1;
// }


/*
 * 假设数组中没有重复元素，若按序排列好则有index=value
 * 遍历元素
 * 若arr[index]=index,则说明该元素在假设位置
 * 若arr[index]!=index,
    * 1.第一次遍历到该值，且该值不在指定位置，假设位置应在arr[value]，调整到假设位置
    * 2.第二次遍历到该值，那么应有arr[value]=value成立，该值重复
 * 时间复杂度O(n+n)，空间复杂度O(1) 
 */
// int findRepeatNumber(int *nums, int numsSize)
// {
//     if (nums == NULL && numsSize <= 0)
//     {
//         return -1;
//     }

//     /*防止非法输入及遍历时出现越界访问*/
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] < 0 || nums[i] >= numsSize)
//         {
//             return -1;
//         }
//     }

//     for (int i = 0; i < numsSize; i++)
//     {
//         /*
//         error:当元素在正确位置时，返回该值，但该值不一定为重复元素
//         if (nums[i] == nums[nums[i]])
//         {
//             return nums[i];
//         }
//         else
//         {
//             int temp = nums[nums[i]];
//             nums[nums[i]] = nums[i];
//             nums[i] = temp;
//         }
//         */
//         while (nums[i] != i)
//         {
//             if (nums[i] == nums[nums[i]])
//             {
//                 return nums[i];
//             }
//             else
//             {
//                 int temp = nums[nums[i]];
//                 nums[nums[i]] = nums[i];
//                 nums[i] = temp;
//             }
//         }
//     }
//     return -1;
// }