/*
 * @Description: 设计一个具有getMIn功能的栈
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 13:43:00
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 13:46:41
 */
#include <stack>

template<typename T>
class getMin
{
    private:
        stack<T> stackData;
        stack<T> stackMin;
    public:
        void pop();
        void push(T elem);
        T get_min();
        bool is_empty();
};