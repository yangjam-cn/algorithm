/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 14:11:48
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 14:19:32
 */
#include <iostream>
using namespace std;

template<typename T>
class TypeInfo
{
    public:
        enum {IsPtrT = 0, IsRefT = 0 ,IsArrayT = 0};
        typedef T baseT;
        typedef T bottomT;
};

template<typename T>
class TypeInfo<T*>
{
    public:
        enum {IsPtrT = 1, IsRefT = 0, IsArrayT = 0};
        typedef T baseT;
        typedef typename TypeInfo<T>::bottomT bottomT;
};

template<typename T>
class TypeInfo<T&>
{
    public:
        enum {IsPtrT = 0, IsRefT = 1, IsArrayT = 0};
        typedef T baseT;
        typedef typename TypeInfo<T>::bottomT bottomT;
};