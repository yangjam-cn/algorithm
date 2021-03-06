/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 09:41:04
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 10:10:08
 */
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iostream>

/* 主类模板 */
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
                return NULL;
            return elems.back();
        }
};

/* 完全模板特化 */
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
                return NULL;
            return elems.back();
        }
};
部分模板特化
/*  */
template<typename T>
class Stack<T*>
{
    private:
        std::list<T*> list;

    public:
        void push(T* elem)
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
                return NULL;
            return list.front();
        }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::string strs[5] = {"hello", "windows", "c++", "template", "vs code"};

    Stack<int> testInt;
    Stack<std::string> testStr;
    Stack<int *> testTptr;

    for (int i = 0; i < 5; i++)
    {
        testInt.push(arr[i]);
        testStr.push(strs[i]);
        testTptr.push(arr + i);
    }

    std::cout << testInt.top() << std::endl;
    std::cout << testStr.top() << std::endl;
    std::cout << *testTptr.top() << std::endl;
    return 0;
}