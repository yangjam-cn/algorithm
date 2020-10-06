/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 20:57:15
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 21:57:04
 */
#include<iostream>


using std::endl;
using std::cout;

template<typename T>
struct SListNode
{
    T m_elem;
    SListNode *m_pNext;
};


template<typename T>
class LinkList
{
    private:
        SListNode<T> *head;
        int length;

        SListNode<T> *create_node(T &elem)
        {
            SListNode<T> *ptr = new SListNode<T>;
            ptr->m_elem = elem;
            ptr->m_pNext = nullptr;
            return ptr;
        }
    public:
        LinkList(SListNode<T> *ptr = nullptr)
        {
            head = ptr;
        }
        LinkList(T elem)
        {
            head = new SListNode<T>;
            head->m_elem = elem;
            head->m_pNext = nullptr;
        }
        ~LinkList();
        bool empty() 
        {
            return head == nullptr;
        }
        /* 定位链表尾部节点 */
        SListNode<T> *locate_tail() const;
        /* 在链表尾部追加元素 */
        void add_to_tail(T &elem);
        /* 打印链表元素 */
        void print_list();
};


template<typename T>
LinkList<T>::~LinkList()
{
    SListNode<T> *ptr = head, *temp;
    while (ptr != nullptr)
    {
        temp = ptr->m_pNext;
        cout << "delete : " << ptr->m_elem << endl;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;
}

template<typename T>
SListNode<T> *LinkList<T>::locate_tail() const
{
    if (head == nullptr)
        return head;
    
    SListNode<T> *tail = head;
    while (tail->m_pNext != nullptr)
        tail = tail->m_pNext;
    return tail;
}

template<typename T>
void LinkList<T>::add_to_tail(T &elem)
{
    if (empty())
    {
        head = create_node(elem);
        return;
    }
    
    SListNode<T> *tail = locate_tail();
    tail->m_pNext = create_node(elem);
}

template<typename T>
void LinkList<T>::print_list()
{
    SListNode<T> *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->m_elem << endl;
        ptr = ptr->m_pNext;
    }
}