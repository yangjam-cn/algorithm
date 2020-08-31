/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: myStack.hpp
 * @Description: 链式栈的简单模板类实现
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-29 08:39:22
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-29 15:18:28
 */
/*基于链表的栈的简单定义*/

/*
入栈
出栈
获取栈顶元素
检查栈是否为空
*/
#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <exception>

template <class T>
struct sNode
{
    T m_nValue;
    sNode<T> *m_pNext;

    sNode() :m_pNext(nullptr){}
    sNode(T t):m_nValue(t), m_pNext(nullptr){}
};

template <class T>
class myStack
{
    int size;
    sNode<T> *pTop;    /*栈顶指针，不存放元素*/

    public:
        myStack() { size = 0; pTop = new sNode<T>; }
        ~myStack();
        void push(T value);
        void pop();
        T get_top();
        bool is_empty();
        int get_size();
};

template <class T>
void myStack<T>::push(T vlaue)
{
    sNode<T> *pNode = new sNode<T>(vlaue);
    pNode->m_pNext = pTop->m_pNext;
    pTop->m_pNext = pNode;
    ++size;
}

template <class T>
void myStack<T>::pop()
{
    if (!is_empty())
    {
        sNode<T> *pTemp = pTop->m_pNext->m_pNext;
        delete pTop->m_pNext;
        pTop->m_pNext = pTemp;
        --size;
    }
}

template <class T>
bool myStack<T>::is_empty()
{
    if (0 == size && pTop->m_pNext == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
T myStack<T>::get_top()
{
    if (!is_empty())
    {
        return pTop->m_pNext->m_nValue;
    }
    return pTop->m_nValue;
}

template <class T>
int myStack<T>::get_size()
{
    return size;
}

template <class T>
myStack<T>::~myStack()
{
    while (!is_empty())
    {
        pop();
    }
    delete pTop;
    pTop = nullptr;
}

#endif