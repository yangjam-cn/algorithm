#include "string1.hpp"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    String name;

    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to " << ArSize 
            << " short sayings<enpty line to quit>:\n";

    String saying[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
}