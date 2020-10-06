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