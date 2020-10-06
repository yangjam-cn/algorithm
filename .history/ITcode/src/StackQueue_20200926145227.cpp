/*
 * @Description: 用两个栈实现队列
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 14:27:31
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 14:52:27
 */
#include <stack>

template <typename T>
class StackQueue
{
    private:
        std::stack<T> m_sEnStack;    /* 入队栈 */
        std::stack<T> m_sDeStack;    /* 出队栈 */
    public:
        StackQueue(){}
        ~StackQueue(){}
        void enqueue(T elem);
        void dequeue();
        bool is_empty();
        T get_head();
};


template<typename T>
void StackQueue<T>::enqueue(T elem)
{
    m_sEnStack.push(elem);
}

template<typename T>
void StackQueue<T>::dequeue()
{
    if (!is_empty())
    {
        if (!m_sDeStack.empty())
            m_sDeStack.pop();
        else
        {
            while (!m_sEnStack.empty())
            {
                m_sDeStack.push(m_sEnStack.top());
                m_sEnStack.pop();
            }
            m_sDeStack.pop();
        }
    }
}

template<typename T>
T StackQueue<T>::get_head()
{
    if (!is_empty())
    {
        if (!m_sDeStack.empty())
            return m_sDeStack.top();
        else
        {
            while (!m_sEnStack.empty())
            {
                m_sDeStack.push(m_sEnStack.top());
                m_sEnStack.pop();
            }
            return m_sDeStack.top();
        }
    }
    return (T)0;
}

template<typename T>
bool StackQueue<T>::is_empty()
{
    return m_sDeStack.empty && m_sEnStack.empty();
}