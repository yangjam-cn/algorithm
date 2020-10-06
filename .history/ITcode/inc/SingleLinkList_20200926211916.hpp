/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 20:57:15
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 21:18:02
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

        SListNode<T> *create_node(T &elem) const
        {
            SListNode<T> *ptr = new SListNode<T>;
            ptr->m_elem = elem;
            ptr->m_pNext = nullptr;
            retrun ptr;
        }
    public:
        LinkList(SListNode<T> *ptr = nullptr)
        {
            head = ptr;
        }
        LinkList(T elem)
        {
            head = new SListNode<T>;
            head.m_elem = elem;
            head.m_pNext = nullptr;
        }
        ~LinkList();
        bool empty() 
        {
            return head == nullptr;
        }
        void add_to_tail(T &elem) const;
        SListNode<T> *locate_tail();
};


template<typename T>
LinkList<T>::~LinkList()
{
    SListNode<T> *ptr = head, *temp;
    while (ptr != nullptr)
    {
        temp = ptr->m_pNext;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;
}

template<typename T>
void LinkList<T>::add_to_tail(T &elem) const
{
    
}