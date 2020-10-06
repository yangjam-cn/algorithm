/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-15 17:39:30
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-15 17:50:03
 */
#include <iostream>
using namespace std;

class Test
{
    private:
        char *m_str;
    public:
        Test(char *str = (char *)"this is default!");
        ~Test();
};

Test::Test(char *str)
{
    m_str = str;
}

Test::~Test()
{
    cout << "delete: " << m_str << endl;
}

int main()
{
    Test test1((char *)"test1");
    Test test2 = Test((char *)"test2");     /*编译器采用直接赋值的策略，而不是临时变量复制*/
    test1 = Test((char *)"test3");
    return 0;
}