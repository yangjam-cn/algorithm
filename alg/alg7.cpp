/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 滑动窗口法
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-13 09:37:37
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-13 10:07:29
 */
#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>


using namespace std;
string min_window(string s, string t)
{
    unordered_map<char, int> need, window;
    
    /*记录串t的字符及数量*/
    for (char c : t)
    {
        need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, length = INT_MAX;
    
    while (right < s.size())    /*当right指向s尾元素时，算法结束*/
    {
        /*划动right，加入窗口*/
        char c = s[right];
        ++right;

        /*当字符为串t中字符时，记录在window中*/
        if (need.count(c) > 0)
        {
            window[c]++;
            if (window[c] == need[c])    /*当字符c满足串t要求后，记录在valid中*/
            {
                ++valid;
            }
        }

        /*当窗口覆盖t的所有字符后*/
        while (valid == need.size())
        {
            /*更新符合要求的最小子串长度*/
            if ((right - left) < length)
            {
                start = left;
                length = right - left;
            }

            /*滑动left缩小窗口*/
            char d = s[left];
            ++left;

            /*当字符d在串t中，缩小窗口后，更新记录*/
            if (need.count(d) > 0)
            {
                if (window[d] == need[d])
                {
                    --valid;
                }
                window[d]--;
            }
        }
    }
    return length == INT_MAX ? "" : s.substr(start, length);
}


int main(void)
{
    string s, t;
    cin >> s;
    cin >> t;
    cout  << min_window(s, t) << endl;
    cout << s.length() << endl;
    cout << s.size() << endl;
    return 0;
}