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
