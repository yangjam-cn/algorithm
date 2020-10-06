/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 10:52:35
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 14:06:50
 */
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

    String sayings[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() !='\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; ++i)
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        
        int shorttest = 0;
        int first = 0;
        for (i = 0; i < total; ++i)
        {
            if (sayings[i].length() < sayings[shorttest].length())
                shorttest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        cout << "Shorttest saying:\n" << sayings[shorttest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany() << " String objects. Bye.\n";
    }
    else 
        cout << "No input! Bye.\n";

    return 0;
}