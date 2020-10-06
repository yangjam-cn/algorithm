/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 20:57:15
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 21:04:07
 */
#include<iostream>

template<typename T>
struct SListNode
{
    T m_elem;
    ListNode *m_pNext;
};


template<typename T>
class LinkList
{
    private:
        SListNode<T> head;
    public:
        LinkList()
        {
            head = nullptr;
        }
        LinkList(T elem)
        {
            head = new SListNode<T>;
            head.elem = elem;
        }
};