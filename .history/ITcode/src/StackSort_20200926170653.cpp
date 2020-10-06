/*
 * @Description: 利用一个栈实现另一个栈的排序
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 16:59:11
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 17:06:53
 */
#include <stack>
using std::stack;

template<typename T>
class StackSort
{
    private:
        stack<T> m_sSatck;
        satck<T> m_sHelp;
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
        T elem = m_sSatck.top();
        m_sSatck.pop();
        return elem;
    }
    return (T)0;
}

template<typename T>
void StackSort<T>::push(T elem)
{
    m_sSatck.push(elem);
}

template<typename T>
bool StackSort<T>::empty()
{
    return m_sSatck.empty();
}
