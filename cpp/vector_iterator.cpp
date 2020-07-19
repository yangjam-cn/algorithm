/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: vector_iterator.cpp
 * @Description: 测试迭代器
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 14:49:43
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 14:55:44
 */ 
#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vi;

    for (int i = 0; i <= 5; i++)
    {
        vi.push_back(i);    /* 在vi的末尾添加元素i */
    }

    vector<int>::iterator it = vi.begin();    /* 将vi首元素地址赋给it */

    for (int i = 0; i <= 5; i++)
    {
        printf("%d ", *(it + i));
    }

    return 0;
}

/*
 * vi.end()为取尾元素地址的下一个地址
 */