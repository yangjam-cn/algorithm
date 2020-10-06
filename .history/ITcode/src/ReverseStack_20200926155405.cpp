#include <stack>

template<typename T>
class ReverseStack
{
    private:
        std::stack<T> m_sStack;
        T get_and_remove_bottom();
    public:
        void reverse();
}