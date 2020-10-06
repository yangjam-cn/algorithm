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