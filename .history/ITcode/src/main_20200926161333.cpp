/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:37:34
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 14:51:19
 */
#include <iostream>
#include <string>
using namespace std;
// #include "GetMin.cpp"
// int main(void)
// {
//     GetMin<int> test;
//     using namespace std;

//     int arr[6] = {3, 2, 2, 4, 1, 5};
//     for (int elem : arr)
//         test.push(elem);
    
//     while (!test.is_empty())
//     {
//         cout << "top is : " << test.get_top() << "\tmin is : " << test.get_min() << endl;
//         test.pop();
//     }

//     return 0;
// }
// #include "StackQueue.cpp"
// int main(void)
// {
//     string strs[] = {"hello", "vs code", "windows", "IT code", "stack && queue"};
//     StackQueue<string> test;

//     for (string str : strs)
//         test.enqueue(str);
    
//     cout << "head is : " << test.get_head() << endl;
//     test.dequeue();

//     for (string str : strs)
//         test.enqueue(str);
    
//     while (!test.is_empty())
//     {
//         cout << "head is : " << test.get_head() << endl;
//         test.dequeue();
//     }

//     return 0;
// }
#include "ReverseStack.cpp"
int main()
{
    ReverseStack<int> test;
    int arr[6] = {1, 2, 3, 4, 5, 6};

    for (int elem : arr)
}