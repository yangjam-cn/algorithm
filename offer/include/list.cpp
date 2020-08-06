/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: list.cpp
 * @Description: 链表实现文件
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 19:13:45
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 21:21:32
 */
#include "list.h"


/*创建新结点*/
ListNode* create_ListNode(int value)
{
    ListNode *pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}


/*连接两个结点*/
void connect_ListNodes(ListNode *pCurrent, ListNode *pNext)
{
    if (pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}


/*打印结点的值*/
void print_ListNode(ListNode *pNode)
{
    if (nullptr == pNode)
    {
        printf("The node is nullptr.\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}


/*打印链表*/
void print_list(ListNode *pHead)
{
    printf("\nPrintList starts.\n");

    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}


/*删除链表*/
void destory_list(ListNode *pHead)
{
    ListNode *pNode = pHead;

    while (pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}


/*向链表尾部添加元素*/
void add_to_tail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if (nullptr == pHead)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}


/*删除链表中的指定元素*/
void remove_node(ListNode **pHead, int value)
{
    if (nullptr == pHead || nullptr == *pHead)
    {
        return;
    }

    ListNode *pToBeDeleted = nullptr;

    if ((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
        {
            pNode = pNode->m_pNext;
        }
        if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pToBeDeleted->m_pNext;
        }
    }

    if (pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}


/*反转链表*/
/*
 * A->B->C->D
 * ==> null<-A B->C->D
    * 保存A的后继B
    * 将A指向null
    * 将新表头指向A
 * ==> null<-A<-B C->D
    * 保存B的后继
    * 将B指向A
    * 将新表头指向B
 */
void reverse_list(ListNode **pHead)
{
    if (nullptr == pHead || nullptr == *pHead)
    {
        return;
    }

    if (nullptr == (*pHead)->m_pNext)
    {
        return;
    }

    ListNode *pNewHead = nullptr;    /*反转后的链表的表头*/
    ListNode *pNext = *pHead;    /*用于保存当前反转结点后继的指针*/
    ListNode *pNode = *pHead;    /*l链表游标，指向当前要反转的结点*/
    while (pNode != nullptr)
    {
        pNext = pNode->m_pNext;    /*保存后继*/
        pNode->m_pNext = pNewHead;    /*反转当前结点*/
        pNewHead = pNode;    /*更新表头*/
        pNode = pNext;    /*更新链表游标*/
    }
    *pHead = pNewHead;    /*更新新表头*/
}
