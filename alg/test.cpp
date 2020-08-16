/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-14 14:08:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-14 19:22:34
 */
#include <iostream>

using namespace std;


void test(int a, int b)
{
    cout << a << '\t' << b << endl;
}

int main(void)
{
    // int a, b;
    // cin >> a >> b;
    // a^=b;
    // b^=a;
    // a^=b;
    // cout << a << '\t' << b << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 0;
    cout << index << endl;
    test(arr[index], arr[++index]);    /*out:2,2; 先arr[++index]，在arr[index]*/
    cout << index << endl;
    test(arr[++index], arr[index]);    /*out:3,2; 先arr[index]，再arr[++index]*/
    cout << index << endl;
    arr[index + 1] = arr[index--];    /*out:1 2 3 4 5; 先计算右再计算左*/
    for (int ele : arr)
        cout << ele << '\t';
    cout << '\n' << index << endl;
    arr[index-- + 1] = arr[index];    /*out:1 2 1 4 5; */
    for (int ele : arr)
        cout << ele << '\t';
    return 0;
}