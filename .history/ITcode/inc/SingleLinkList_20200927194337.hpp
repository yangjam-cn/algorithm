/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 20:57:15
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-27 19:43:37
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
            length = 0;
        }
        LinkList(T elem)
        {
            head = new SListNode<T>;
            head->m_elem = elem;
            head->m_pNext = nullptr;
            length = 0;
        }
        ~LinkList();
        bool empty() 
        {
            return head == nullptr;
        }
        /* 获取头结点元素 */
        T get_elem()
        {
            return head->m_elem;
        }
        /* 获取后继结点指针 */
        SListNode<T> *get_pNext()
        {
            return head == nullptr ? nullptr : head->m_pNext;
        }
        /* 定位链表尾部节点 */
        SListNode<T> *locate_tail() const;
        /* 在链表尾部追加元素 */
        void add_to_tail(T &elem);
        /* 返回链表长度 */
        int length();
        /* 返回序列在index的节点元素 */
        T operator[](int index);
        /* 打印链表元素 */
        void operator<<();
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
int LinkList<T>::length()
{
    int length = 0;
    SListNode<T> *ptr = head;
    while (ptr != nullptr)
    {
        ++length;
        ptr = ptr->m_pNext;
    }
    return length;
}

template<typename T>
T LinkList<T>::operator[](int index)
{
    if (index >= length())
        return T();
    SListNode<T> *ptr = head;
    for (int i = 0; i < index; ++i)
        ptr = ptr->m_pNext;
    return ptr->m_elem;
}

template<typename T>
void LinkList<T>::operator<<()
{
    SListNode<T> *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->m_elem << endl;
        ptr = ptr->m_pNext;
    }
}