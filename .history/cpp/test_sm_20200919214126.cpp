#include <iostream>

using namespace std;

void fun1()
{
    int a;
    cout << &a << endl;
    int *p = new int;
    if (p != nullptr)
        cout << "new :" << p << endl;
    delete p;
}

int main(void)
{
    void (*p)(void) = mian;
    cout << "main = " << p << endl;
    fun1();
    return 0;
}