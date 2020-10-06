/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 09:41:04
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 09:53:07
 */
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iostream>

template<typename T>
class Stack
{
    private:
        std::vector<T> elems;
    
    public:
        void push(T const &elem)
        {
            elems.push_back(elem);
        }
        void pop()
        {
            if (elems.empty())
                return;
            elems.pop_back();
        }
        T top() const
        {
            if (elems.empty())
                return;
            return elems.back();
        }
};

template<>
class Stack<std::string>
{
    private:
        std::deque<std::string> elems;
    public:
        void push(const std::string &elem)
        {
            elems.push_back(elem);
        }

        void pop()
        {
            if (elems.empty())
                return;
            elems.pop_back();
        }

        std::string top() const
        {
            if (elems.empty())
                return;
            return elems.back();
        }
};

template<typename T>
class Stack<T*>
{
    private:
        std::list<T*> list;

    public:
        void push(T* &elem)
        {
            list.push_front(elem);
        }

        void pop()
        {
            if (list.empty())
                return;
            list.pop_front();
        }

        T* top() const
        {
            if (list.empty())
                return;
            return list.front();
        }
};

int main()
{
    
}