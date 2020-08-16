/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-14 14:43:35
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-14 16:18:02
 */ 
/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.73%)
 * Likes:    1682
 * Dislikes: 0
 * Total Accepted:    324.9K
 * Total Submissions: 774.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
/* 
 * 构造栈，利用栈结构解决
 */
// struct node
// {
//     char item;
//     struct node *next;
// };
// typedef struct node *stack;

// stack push(stack s, char item)
// {
//     stack top;
//     if (s == NULL)
//     {
//         s = (stack)malloc(sizeof(struct node));
//         s->item = item;
//         s->next = NULL;
//     }
//     else
//     {
//         top = (stack)malloc(sizeof(struct node));
//         top->item = item;
//         top->next = s;
//         s = top;
//     }
//     return s;
// }

// stack pop(stack s)
// {
//     stack temp;
//     if (s != NULL)
//     {
//         temp = s->next;
//         free(s);
//         s = temp;
//     }
//     return s;
// }

// char get_top(stack s)
// {
//     if (s != NULL)
//     {
//         return s->item;
//     }
//     else
//     {
//         return '\0';
//     }
// }

// bool isValid(char * s){
//     stack st = NULL;
//     char *str = s;
//     char item;
//     while (*str != '\0')
//     {
//         if ((*str == '(') || (*str == '[') || (*str == '{'))
//         {
//             st = push(st, *str);
//         }
//         else if (*str == ')' || *str == ']' || *str == '}')
//         {
//             item = get_top(st);
//             if ((*str == ')' && item == '(') || (*str == ']' && item == '[')
//                 || (*str == '}' && item == '{'))
//             {
//                 st = pop(st);
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         str++;
//     }
//     if (st == NULL)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
bool isValid(char *s)
{
    if (s == NULL || s[0] == '\0')
        return true;
    char *st = (char *)malloc(sizeof(char) * strlen(s));
    int top = 0;
    while (*s != '\0')
    {
        if ((*s == '(') || (*s == '[') || (*s == '{'))
        {
            st[top++] = *s;
        }
        else
        {
            if ((--top) < 0)
            {
                return false;
            }
            if ((*s == ')' && st[top] != '(') || (*s == ']' && st[top] != '[')
                || (*s == '}' && st[top] != '{'))
            {
                return false;
            }
        }
        s++;
    }
    return (top <= 0);
}

// @lc code=end

