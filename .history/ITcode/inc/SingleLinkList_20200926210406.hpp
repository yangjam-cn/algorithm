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