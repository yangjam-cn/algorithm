/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 寻找两个正序数组的中位数
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-18 21:53:15
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-19 09:09:04
 */ 
/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int length = nums1Size + nums2Size;
    int nums[length];
    double mid;

    int cnt = 0, cnt1 = 0, cnt2 = 0;
    /* 
     * 算法思路
     * 遍历的方式合并两个有序数组,O(nums1Size+nums2Size) 
     * 取中位数，O(1)
     */
    while (cnt < length)
    {
        if (cnt1 < nums1Size && cnt2 < nums2Size)
        {
            if (nums1[cnt1] <= nums2[cnt2])
            {
                nums[cnt++] = nums1[cnt1++];
            }
            else
            {
                nums[cnt++] = nums2[cnt2++];
            }
        }
        else if (cnt1 >= nums1Size && cnt2 < nums2Size)
        {
            nums[cnt++] = nums2[cnt2++];
        }
        else
        {
            nums[cnt++] = nums1[cnt1++];
        }
    }
    if (length % 2 == 0)
    {
        mid = (nums[length / 2] + nums[length / 2 - 1]) / 2.0;
    }
    else
    {
        mid = nums[length / 2];
    }
    return mid;
}


// @lc code=end

