/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-12 19:11:52
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-12 21:58:09
 */
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdio>
#include <algorithm>

using namespace std;

int binary_search_base(int *arr, int length, int target)
{
    int left = 0, right = length - 1;

    while (left <= right)    /*搜索[left, right]*/
    {
        int mid = left + (right - left) / 2;    /*防止(left + right)溢出*/
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;    /*搜索[mid + 1, right]*/
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;    /*搜索[left, mid - 1]*/
        }
    }
    return -1;
}

/*0，2，2，2，3，4，5，6*/
/**target=2**/
/*mid = 3->2, right=2*/
/*mid = 1->2, right=1*/
/*mid = 0->0, left = 1*/
/*end*/
/**target = 3**/
/*mid = 3->2, left = 3*/
/*mid = 5->4, right = 5*/
/*mid = 4->3, right = 4*/
/*mid = 3->2, left = 4*/
/*end*/

int binary_search_left_bound(int *arr, int length, int target)
{
    int left = 0; 
    int right = length;
    
    while (left < right)    /*search [left, right)*/
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)    /*边界为mid或者在mid左侧*/
        {
            right = mid;    /*search [left, mid)*/
        }
        else if (arr[mid] < target)    /*边界在mid右侧且不含mid*/
        {
            left = mid + 1;    /*search [mid + 1, right)*/
        }
        else if (arr[mid] > target)    /*边界在mid左侧*/
        {
            right = mid;    /*search [left, mid)*/
        }
    }    /*end while(left == right)*/
    if (left == length || arr[left] != target)
    {
        return -1;
    }
    return left;
}

int binary_search_right_bound(int *arr, int length, int target)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            left = mid + 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else if(arr[mid] > target)
        {
            right = mid - 1;
        }
    }    /*end while(left = right + 1)*/
    /*right=-1,left=0;right=length-1,left=length*/
    if (right < 0 || arr[right] != target)
    {
        return -1;
    }
    return right;
}

int main(void)
{
    int length;
    srand((unsigned int)time(NULL));
    cin >> length;
    int *arr = new int [length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 10;
    }
    sort(arr, arr + length);

    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    int target;
    cin >> target;
    cout << binary_search_base(arr, length, target) << endl;

    cout << binary_search_left_bound(arr, length, target) << endl;

    cout << binary_search_right_bound(arr, length, target) << endl;

    return 0;
}