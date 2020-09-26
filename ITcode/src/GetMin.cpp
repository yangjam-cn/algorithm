/*
 * @Description: 设计一个具有getMIn功能的栈
 * 假设当前辅助栈顶为当前栈中最小值，若每次入栈都将最小值加入栈顶，则栈顶始终为当前最小值
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:43:00
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 14:26:44
 */
#include <stack>

template<typename T>
class GetMin
{
    private:
        std::stack<T> stackData;
        std::stack<T> stackMin;
    public:
        GetMin() {}
        ~GetMin() {}
        void pop();
        void push(T elem);
        T get_min();
        T get_top();
        bool is_empty();
};


template<typename T>
void GetMin<T>::pop()
{
    if (!is_empty())
    {
        stackData.pop();
        stackMin.pop();
    }
}

template<typename T>
void GetMin<T>::push(T elem)
{
    stackData.push(elem);
    if (stackMin.empty() || elem <= stackMin.top())
        stackMin.push(elem);
    else
        stackMin.push(stackMin.top());
}

template<typename T>
T GetMin<T>::get_min()
{
    if (!is_empty())
        return stackMin.top();
    return (T)0;
}

template<typename T>
T GetMin<T>::get_top()
{
    if (!is_empty())
        return stackData.top();
    return (T)0;
}

template<typename T>
bool GetMin<T>::is_empty()
{
    return stackData.empty() && stackMin.empty();
}