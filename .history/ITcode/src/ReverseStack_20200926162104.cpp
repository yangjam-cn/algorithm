/*
 * @Description: 利用递归函数逆序栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 15:51:02
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 16:21:04
 */
#include <stack>

template<typename T>
class ReverseStack
{
    private:
        std::stack<T> m_sStack;
        T get_and_remove_bottom();
    public:
        void reverse();
        void push(T elem);
        T pop();
        bool is_empty();
};

template<typename T>
T ReverseStack<T>::get_and_remove_bottom()
{
    /* 防止栈为空的情况，不可能执行 */
    if (m_sStack.empty())
        return (T)0;

    /* 获取栈顶元素 */
    T elem = m_sStack.top();
    m_sStack.pop();

    /* 到达栈底 */
    if (m_sStack.empty())
        return elem;
    /* 递归访问栈元素 */
    else
    {
        T bottom = get_and_remove_bottom();    /* 递归寻找栈底元素 */
        m_sStack.push(elem);    /* 非栈底元素在调用层重新入栈 */
        return bottom;
    }
}

template<typename T>
void ReverseStack<T>::reverse()
{
    if (m_sStack.empty())
        return;
    T bottom = get_and_remove_bottom();    /* 获取栈底元素 */
    reverse();    /* 反转栈 */
    m_sStack.push(bottom);    /* 栈底元素最后入栈，完成反转 */
}

template<typename T>
void ReverseStack<T>::push(T elem)
{
    m_sStack.push(elem);
}

template<typename T>
T ReverseStack<T>::pop()
{
    if (!is_empty())
    {
        T elem = m_sStack.top();
        m_sStack.pop();
        return elem;
    }
    return (int)0;
}

template<typename T>
bool ReverseStack<T>::is_empty()
{
    return m_sStack.empty();
}