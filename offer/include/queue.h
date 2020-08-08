/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 08:24:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-08 09:04:30
 */
#pragma once
#include <stack>
#include <cstdio>
#include <cstdlib>


using namespace std;


template <typename T> class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);

        /*在队列尾部添加结点*/
        void append_tail(const T &node);
        /*删除队列头结点*/
        T delete_head();
    
    private:
        stack<T> stack1;
        stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}


template <typename T> CQueue<T>::~CQueue(void)
{
}


template <typename T> void CQueue<T>::append_tail(const T &element)
{
    stack1.push(element);
}

template <typename T> T CQueue<T>::delete_head()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0)
    {
        printf("queue is empty.\n");
        abort();
    }

    T head = stack2.top();
    stack2.pop();

    return head;
}
