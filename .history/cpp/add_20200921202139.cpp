/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-21 20:15:22
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-21 20:21:39
 */
#include <iostream>

using namespace std;

int add1(int a, int b)
{
    return a + b;
}

class ADD
{
    public:
        int operator()(int a, int b){return a + b;}
};

template<typename T, typename U>
auto add3(T a, U b) -> decltype(a + b)
{
    return a + b;
}

auto add4 = [](int a, int b){
    return a + b;
};

int main()
{
    ADD add2;
    cout << add1(3, 4) << endl;
    cout << add2(3, 4) << endl;
    cout << add3(3, 4) << endl;
    cout << add4(3, 4) << endl;

}