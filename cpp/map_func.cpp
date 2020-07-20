/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: map_func.cpp
 * @Description: map函数示例
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 20:59:37
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-20 10:49:51
 */ 
#include <map>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    map<int, string> mp;
    map<int, string>::iterator it;
    int length;
    string str;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> str;
        mp[i] = str;
    }

    cout << mp.size() << endl;

    it = mp.begin();
    while (it != mp.end())
    {
        cout << it->first << "->" << it->second << endl;
        // printf("%d->%s\n",it->first, it->second.c_str());
        it++;
    }

    int key;
    cin >> key;
    it = mp.find(key);
    cout << it->second << endl;

    mp.clear();

    return 0;
}