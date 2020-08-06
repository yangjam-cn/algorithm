/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 19:00:42
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 21:10:13
 */
#include "include/list.h"
#include <stack>

void print_list_reversingly_iteratively(ListNode *pHead)
{
    std::stack<ListNode*> nodes;
    
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

void print_list_reversingly_recursively(ListNode *pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            print_list_reversingly_recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}

void test(ListNode *pHead)
{
    print_list(pHead);
    print_list_reversingly_iteratively(pHead);
    printf("\n");
    print_list_reversingly_recursively(pHead);
}

void test1()
{
    printf("\ntest1 begins.\n");

    ListNode *pHead = create_ListNode(1);
    add_to_tail(&pHead, 2);
    add_to_tail(&pHead, 3);
    add_to_tail(&pHead, 4);
    add_to_tail(&pHead, 5);

    test(pHead);

    reverse_list(&pHead);
    print_list(pHead);

    destory_list(pHead);
}

void test2()
{
    printf("\ntest2 begins.\n");

    ListNode *pHead = create_ListNode(1);

    test(pHead);

    destory_list(pHead);
}

void test3()
{
    printf("\ntest3 begins.\n");

    test(nullptr);
}

int main(void)
{
    test1();
    test2();
    test3();

    return 0;
}
