/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 08:37:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-08 08:43:38
 */
#include "include/queue.h"

void test(char actual, char expected)
{
    if (actual == expected)
    {
        printf("test passed.\n");
    }
    else
    {
        printf("test failed.\n");
    }
}


int main(void)
{
    CQueue<char> queue;

    queue.append_tail('a');
    queue.append_tail('b');
    queue.append_tail('c');

    char head = queue.delete_head();
    test(head, 'a');

    head = queue.delete_head();
    test(head, 'b');

    queue.append_tail('d');
    head = queue.delete_head();
    test(head, 'c');

    queue.append_tail('e');
    head = queue.delete_head();
    test(head, 'd');

    head = queue.delete_head();
    test(head, 'e');

    return 0;
}