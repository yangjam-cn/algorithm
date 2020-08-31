/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 利用递归函数反转栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 15:36:33
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 16:38:53
 */
#include "../inc/myStack.hpp"
#include <iostream>

/*
假定两个栈s1，s2
取出s1中栈顶元素，压入s2中，直到s1为空，s2中即为s1的反序
递归函数相当栈，调用相当于入栈，返回相当于出栈
*/

int get_bottom(myStack<int> &sp)
{
    int data = sp.get_top();
    sp.pop();

    if (sp.is_empty())    /*栈底元素，返回*/
    {
        return data;
    }
    else    /*否则，继续递归*/
    {
        int res = get_bottom(sp);
        sp.push(data);    /*返回该层时将弹出元素压入栈中，不改变栈中元素的相关顺序*/
        return res;
    }
}


void reverse_stack(myStack<int> &sp)
{
    if (sp.is_empty())
    {
        return;
    }
    int data = get_bottom(sp);    /*获取栈底元素*/
    reverse_stack(sp);
    sp.push(data);                      /*栈底元素最后压入栈中*/
}

void traverse_stack(myStack<int> &sp)
{
    using std::cout;
    if (sp.is_empty())
        return;
    else
    {
        int data = sp.get_top();
        sp.pop();
        cout << "head: " << data << '\n';
        traverse_stack(sp);
        sp.push(data);
    }
    
}

int main(void)
{
    using std::cin;
    using std::cout;
    myStack<int> s;
    int size, value;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cin >> value;
        s.push(value);
    }
    traverse_stack(s);
    reverse_stack(s);
    cout << "reversed!\n";
    while (!s.is_empty())
    {
        cout << s.get_top() << '\n';
        s.pop();
    }
    return 0;
}