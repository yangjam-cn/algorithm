/*
 * @Description: 设计一个具有getMIn功能的栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:43:00
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 13:58:16
 */
#include <stack>

template<typename T>
class getMin
{
    private:
        std::stack<T> stackData;
        std::stack<T> stackMin;
    public:
        void pop();
        void push(T elem);
        T get_min();
        T get_top();
        bool is_empty();
};


template<typename T>
void getMin<T>::pop()
{
    stackData.
}