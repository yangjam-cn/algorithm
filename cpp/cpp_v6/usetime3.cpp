/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-16 21:45:41
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-16 21:52:31
 */
#include "mytime3.hpp"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca = Time(2, 43);
    Time temp;

    cout << "aida and tosca:\n";
    cout << aida << ";" << tosca << endl;
    temp = aida + tosca;
    cout << "aida + tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "aida * 1.17: " << temp << endl;
    cout << "10.0 * tosca: " << 10.0 * tosca << endl;

    #ifdef DBUG
        cout << __LINE__ << endl;
    #endif

    return 0;
}