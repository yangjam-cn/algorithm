/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-14 12:45:18
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-14 13:32:13
 */ 
/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (37.37%)
 * Likes:    1155
 * Dislikes: 0
 * Total Accepted:    309.1K
 * Total Submissions: 804.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    int cnt_str = 0, cnt_ch = 0;
    int flag = 1;
    if (0 == strsSize)
        return "";
    for (cnt_ch = 0; strs[0][cnt_ch] != '\0' && flag; cnt_ch++)
    {
        for (cnt_str = 1; cnt_str < strsSize; cnt_str++)
        {
            if (strs[0][cnt_ch] != strs[cnt_str][cnt_ch])
            {
                strs[0][cnt_ch] = '\0';
                flag = 0;
                break;
            }
        }
    }
    return strs[0];
}


// @lc code=end

