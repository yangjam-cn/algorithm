#include <iostream>
#include <stack>

using std::stack;
class Hanoi
{
    private:
        stack<int> m_siStackA;
        stack<int> m_siStackB;
        stack<int> m_siStackC;

        void move_one(char from, char to);
    public:
        Hanoi(stack<int> s)
        {
            m_siStackA = s;
        }

        void HanoiPro();
        void HanoiPro(char from, char to, int size);
};



