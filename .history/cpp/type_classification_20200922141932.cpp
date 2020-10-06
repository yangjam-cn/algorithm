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