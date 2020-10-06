/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 14:48:38
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 15:04:56
 */
#include <iostream>

template<class T>
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
        ~Vector()
        {
            delete [] v;
        }
        T & operator[](int i)
        {
            return v[i];
        }
};

typedef Vector<void *> VPVector;

template<class T>
class Vector<T*>: public VPVector
{
    public:
        T* & operator[](int i)
        {
            return (T* &)(VPVector::operator[](i));
        }
};


int main()
{
    Vector<int *> v1;
    Vector<double *> v2;

    int i = 3;
    v1[0] = &i;
    double d = 3.14;
    v2[0] = &d;

    return 0;
}