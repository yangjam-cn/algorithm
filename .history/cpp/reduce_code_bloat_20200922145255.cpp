/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 14:48:38
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 14:52:55
 */
#include <iostream>

template<typename T>
class Vector
{
    private:
        T *v;
        int sz;
    public:
        Vector(int size = 100)
        {
            v = new T[size];
            sz = size;
        }

}