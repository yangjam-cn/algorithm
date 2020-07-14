/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.27%)
 * Likes:    1146
 * Dislikes: 0
 * Total Accepted:    390.9K
 * Total Submissions: 669.6K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start

/*
 * 利用回文数反转后与自身相等的特点
 */
// bool isPalindrome(int x){
//     int temp;
//     long y;    /* 防止非回文数出现溢出 */
//     if (x < 0)
//     {
//         return false;
//     }
//     else
//     {
//         temp = x;
//         y = 0;
//         /* 整数反转 */
//         while (temp != 0)
//         {
//             y = y * 10 + temp % 10;
//             temp /= 10;
//         }
//         if ( x == y)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }
bool isPalindrome(int x)
{
    int temp = x;
    long y = 0;
    if (x < 0)
        return false;
    else if (x < 10)
        return true;
    else if ((x % 10) == 0)
        return false;
    else
    {
        while (temp != 0)
        {
            y = y * 10 + temp % 10;
            temp /= 10;
        }
        if (y == x)
            return true;
        else
            return false;
    }
    
}
// @lc code=end

