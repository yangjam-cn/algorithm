/*
 * @Description: 利用一个栈实现另一个栈的排序
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 16:59:11
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 17:03:10
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
