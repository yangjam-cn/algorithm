/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:37:34
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-27 20:29:51
 */
#include <iostream>
#include <string>
#include <iomanip>
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
// #include "ReverseStack.cpp"
// int main()
// {
//     ReverseStack<int> test;
//     int arr[6] = {1, 2, 3, 4, 5, 6};

//     for (int elem : arr)
//         test.push(elem);
    
//     test.reverse();

//     while (!test.is_empty())
//         cout << "top is: " << test.pop() << endl;
    
//     return 0;
// }
// #include "StackSort.cpp"

// int main(void)
// {
//     StackSort<float> test;
//     float arr[] = {1.2, 2.31, 1.5, 3.4, 2.5, 4.3, 3.2};

//     for (float x : arr)
//         test.push(x);

//     test.sort();

//     cout << setprecision(3) << endl;
//     while (!test.empty())
//         cout << test.pop() << endl;
    
//     return 0;
// }
#include "../inc/SingleLinkList.hpp"

int main()
{
    LinkList<int> test;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int elem : arr)
        test.add_to_tail(elem);
    cout << "test[3] = " << test[3] << endl;
    test[3] = 12;

    cout << "head->elem = " << test.get_elem() << endl;
    SListNode<int> *ptr = test.get_pNext();
    cout << "next->elem = " << ptr->m_elem << endl;

    cout << test;
    return 0;
}