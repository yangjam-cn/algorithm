/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: set_func.cpp
 * @Description: set常用函数示例
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 15:55:23
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 16:07:11
 */ 
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

int main(void)
{
    set<int> st;
    set<int>::iterator it;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 6; i++)
    {
        st.insert((rand() % 100));
    }

    printf("%u\n", st.size());

    it = st.begin();
    for (int i = 0; i < st.size(); i++)
    {
        printf("%d ", *(it++));
    }
    putchar('\n');

    printf("%p\n", st.begin());
    int value;
    scanf("%d", &value);
    printf("%p\n", st.find(value));

    it = st.find(value);
    st.erase(st.begin(), it);
    it = st.begin();
    while (it != st.end())
    {
        printf("%d ", *(it++));
    }
    putchar('\n');

    st.clear();
    
    return 0;
}
