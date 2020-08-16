/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: test_srr_ptr.cpp
 * @Description: 测试指针与数组名的差异
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 08:52:51
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 09:06:44
 */
#include <iostream>
using std::cout;
using std::endl;
void sizeof_arg_of_array(int arr[])
{
    cout << sizeof(arr) << endl;
}


int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sizeof(arr) << endl;    /*输出数组的大小*/

    int *ptr = arr;
    cout << sizeof(ptr) << endl;    /*输出指针的大小*/

    sizeof_arg_of_array(arr);       /*数组名作为函数参数会自动退化为同类型指针*/
    return 0;
}

/*
 output: 20 8 8
 64位操作系统，故指针大小为8
 */