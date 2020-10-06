/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-30 15:10:46
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-30 15:28:35
 */
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

void Hanoi::move_one(char from, char to)
{
    int elem;
    switch (from)
    {
        case 'A':
        {
                if (to == 'B')
                {
                    elem = m_siStackA.top();
                    m_siStackA.pop();
                    m_siStackB.push(elem);
                }
                else if (to == 'C')
                {
                    elem = m_siStackA.top();
                    m_siStackA.pop();
                    m_siStackB.push(elem);
                    m_siStackB.pop();
                    m_siStackC.push(elem);
                }
                break;
        }
        case 'B':
        {
            if (to == 'A')
            {
                elem = m_siStackB.top();
                m_siStackB.pop();
                m_siStackA.push(elem);
            }
            else if (to == 'C')
            {
                elem = m_siStackB.top();
                m_siStackC.pop();
                m_siStackC.push(elem);
            }
            break;
        }
    }
}

