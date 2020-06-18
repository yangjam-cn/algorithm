/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 整数反转.c
 * @Description: 整数反转
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-18 16:31:05
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-18 21:32:36
 */ 
/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    /*
     * 核心算法
     * int result = 0; 
     * while (x != 0)
     * {
     *     result = result * 10 + x % 10;
     *     x /= 10;
     * }
     */
    long result = 0;
    int max = 0x7fffffff;
    int min = 0x80000000;
    if (x == 0)
    {
        return 0;
    }
    else if (x > 0)
    {
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
    }
    else
    {
        if (x <= min)
        {
            return 0;
        }
        else
        {
            x = -x;
            while (x != 0)
            {
                result = result * 10 + x % 10;
                x /= 10;
            }
            result = -result;
        }
        
    }
    if (result > max || result < min)
    {
        result = 0;
    }
    return result;
}


// @lc code=end

