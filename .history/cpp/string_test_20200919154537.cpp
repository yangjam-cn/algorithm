#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str1, str2;
    char ch;

    int M = 234;
    int N = 2;
    while (M > 0)
    {
        ch = (M % N) + '0';
        str1 = str1 + ch;
        M = M / N;
    }
    cout << str1;
}