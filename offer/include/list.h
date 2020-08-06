/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: list.h
 * @Description: 链表头文件
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 19:05:23
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 21:10:47
 */
#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int          m_nValue;
    ListNode *m_pNext;
};


__declspec( dllexport ) ListNode* create_ListNode(int value);
__declspec( dllexport ) void connect_ListNodes(ListNode *pCurrent, ListNode *Next);
__declspec( dllexport ) void print_ListNode(ListNode *pNode);
__declspec( dllexport ) void print_list(ListNode *pHead);
__declspec( dllexport ) void destory_list(ListNode *pHead);
__declspec( dllexport ) void add_to_tail(ListNode **pHead, int value);
__declspec( dllexport ) void remove_node(ListNode **pHead, int value);
__declspec( dllexport ) void reverse_list(ListNode **pHead); 