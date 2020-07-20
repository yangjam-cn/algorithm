/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: stack_test
 * @Description: 中缀表达式的转换与测试
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-20 20:23:22
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-20 22:00:55
 */ 
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node
{
    double m_num;     /* 操作数 */
    char   m_op;      /* 操作符 */
    bool   m_flag;    /* true表示操作数，false表示操作符 */
};

string g_str;           /* 输入字符串 */
stack<node> g_s;        /* 全局栈，暂存操作符和操作数 */
queue<node> g_q;        /* 全局队列，保存后缀表达式队列 */
map<char, int> g_op;    /* 建立操作符优先级映射 */


/**
 * @Function: infix_to_postfix
 * @Description: 将中缀表达式转化为后缀表达式
 * @Input: void
 * @Output: 
 * @Return: void
 * @Others: 
 */
void infix_to_postfix(void)
{
    double num;
    node   temp;

    /* 遍历表达式 */
    for (int i = 0; i < g_str.length();)
    {
        /* 如果字符是数字 */
        if ((g_str[i] >= '0') && (g_str[i] <= '9'))
        {
            temp.m_flag = true;    /* 标记为操作数 */

            temp.m_num = g_str[i++] - '0';    /* 存放操作数首位数字 */
            /* 若接下来的字符还是数字，表明是多位数 */
            while ((i < g_str.length()) 
                && ((g_str[i] >= '0') && (g_str[i] <= '9')))
            {
                /* 更新操作数 */
                temp.m_num = temp.m_num * 10 + (g_str[i++] - '0');
            }
            g_q.push(temp);    /* 将操作数加入队列 */
        }    /*  end if */
        /* 如果字符是操作符 */
        else
        {
            temp.m_flag = false;    /* 标记为操作符 */

            /* 如果栈外操作符优先级小于等于栈顶优先级，则弹出操作符 */
            while ((!g_s.empty()) && (g_op[g_str[i]] <= g_op[g_s.top().m_op]))
            {
                g_q.push(g_s.top());    /* 将栈顶操作符加入队列 */
                g_s.pop();    /* 弹出栈顶元素 */
            }
            /* 若栈外操作符优先级高于栈内，则压入栈中 */
            temp.m_op = g_str[i++];
            g_s.push(temp);
        }    /* end else */
    }
    /* 遍历完字符串后，若栈内非空，则依次弹出栈内操作符，加入队列 */
    while (!g_s.empty())
    {
        g_q.push(g_s.top());
        g_s.pop();
    }
}


/**
 * @Function: calculate_postfix
 * @Description: 计算后缀表达式的值
 * @Input: void
 * @Output: 
 * @Return: 后缀表达式计算后的结果
 * @Others: 
 */
double calculate_postfix(void)
{
    double num1, num2;    /* 临时操作数变量 */
    node cur, temp;       /* 操作数(符)临时结构体变量 */

    /* 遍历后缀表达式队列 */
    while (!g_q.empty())
    {
        cur = g_q.front();    /* cur为队首元素 */
        g_q.pop();

        /* 如果为操作数，则压入栈中 */
        if (cur.m_flag)
        {
            g_s.push(cur);
        }
        /* 如果是操作符，则计算结果 */
        else
        {
            /*弹出操作数*/
            num2 = g_s.top().m_num;
            g_s.pop();
            num1 = g_s.top().m_num;
            g_s.pop();

            temp.m_flag = true;    /* 将计算结果标记为操作数 */

            /* 根据操作符计算结果 */
            if (cur.m_op == '+')
            {
                temp.m_num = num1 + num2;
            }
            else if (cur.m_op == '-')
            {
                temp.m_num = num1 - num2;
            }
            else if (cur.m_op == '*')
            {
                temp.m_num = num1  * num2;
            }
            else
            {
                temp.m_num = num1 / num2;
            }

            g_s.push(temp);    /* 将结果重新压入栈中 */
        }
    }
    return g_s.top().m_num;    /* 栈顶元素即为计算结果 */
}


int main(void)
{
    g_op['+'] = g_op['-'] = 1;
    g_op['*'] = g_op['/'] = 2;

    while (getline(cin, g_str), g_str != "0")
    {
        /* 遍历字符串，除去空格 */
        for (string::iterator it = g_str.end(); it != g_str.begin(); it--)
        {
            if (*it == ' ')
            {
                g_str.erase(it);
            }
        }
        /* 栈非空时，初始化栈 */
        while (!g_s.empty())
        {
            g_s.pop();
        }

        infix_to_postfix();
        printf("%.2f\n", calculate_postfix());
        
    }
    return 0;
}