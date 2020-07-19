/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: vector_func.cpp
 * @Description: 测试vector函数
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 15:06:03
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-19 15:17:28
 */ 
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    vector<int> vi;
    int length = 6;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        vi.push_back((rand() % 100));
    }

    printf("%u\n", vi.size());
    for (int i = 0; i < length; i++)
    {
        printf("%d ", vi[i]);
    }
    putchar('\n');

    vi.pop_back();
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", *(vi.begin() + i));
    }
    putchar('\n');

    vi.insert(vi.end() - 3, 45);
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", *(vi.begin() + i));
    }
    putchar('\n');

    vi.erase(vi.begin(), vi.end() - 3);
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", *(vi.begin() + i));
    }
    putchar('\n');
    
    vi.clear();
    printf("%u", vi.size());

    return 0;
}