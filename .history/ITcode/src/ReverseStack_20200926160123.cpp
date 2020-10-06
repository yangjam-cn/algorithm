/*
 * @Description: 利用递归函数逆序栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 15:51:02
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 16:01:23
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
};

template<typename T>
T ReverseStack<T>::get_and_remove_bottom()
{
    if (m_sStack.empty())
        return (T)0;
    T elem = m_sStack.top();
    m_sStack.pop();
    if (m_sStack.empty())
        return elem;
    else
    {
        T last = get_and_remove_bottom();
        m_sStack.push(elem);
        return last;
    }
}