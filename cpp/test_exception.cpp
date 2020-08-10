/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-08 14:47:26
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-08 15:11:57
 */
#include <iostream>
#include <exception>


int main(void)
{
    using namespace std;
    int input, output;
    cin >> input;
    // try
    // {
        if (input < 0)
        {
            throw invalid_argument("input must be greater than 0.");
        }
        output = input * 2;
        cout << output << endl;
    // }
    // catch(invalid_argument &msg)
    // {
    //     cout << msg.what() << endl;
    // }
    return 0;
}