/*
 * @Description: 利用一个栈实现另一个栈的排序
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 16:59:11
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 19:44:30
 */
#include <stack>
using std::stack;

template<typename T>
class StackSort
{
    private:
        stack<T> m_sStack;
        stack<T> m_sHelp;
    public:
        T pop();
        void push(T elem);
        void sort();
        bool empty();
};

template<typename T>
T StackSort<T>::pop()
{
    if (!empty())
    {
        T elem = m_sStack.top();
        m_sStack.pop();
        return elem;
    }
    return T();
}

template<typename T>
void StackSort<T>::push(T elem)
{
    m_sStack.push(elem);
}

template<typename T>
bool StackSort<T>::empty()
{
    return m_sStack.empty();
}

/* 对栈进行排序，从底到顶按升序排列 */
template<typename T>
void StackSort<T>::sort()
{
    while (!m_sStack.empty())
    {
        T top = m_sStack.top();
        m_sStack.pop();
        
        while (!m_sHelp.empty() && m_sHelp.top() < top)
        {
            m_sStack.push(m_sHelp.top());
            m_sHelp.pop();
        }

        m_sHelp.push(top);
    }

    while (!m_sHelp.empty())
    {
        T top = m_sHelp.top();
        m_sStack.push(top);
        m_sHelp.pop();
    }
}
