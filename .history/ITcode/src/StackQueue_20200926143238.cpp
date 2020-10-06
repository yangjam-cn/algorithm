/*
 * @Description: 用两个栈实现队列
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 14:27:31
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 14:32:38
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
        T get_top();
};