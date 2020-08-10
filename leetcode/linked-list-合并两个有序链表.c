/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (62.76%)
 * Likes:    1195
 * Dislikes: 0
 * Total Accepted:    336.9K
 * Total Submissions: 527.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (NULL == l1 || NULL == l2)
    {
        if (NULL == l1)
        {
            return l2;
        }
        else
        {
            return l1;
        }
    }

    struct ListNode *pNewHead;
    if (l1->val <= l2->val)
    {
        pNewHead = l1;
        l1 = l1->next;
    }
    else
    {
        pNewHead = l2;
        l2 = l2->next;
    }
    
    struct ListNode *pCurNode = pNewHead;
    struct ListNode *pNode1 = l1;
    struct ListNode *pNode2 = l2;

    while (pNode1 != NULL && pNode2 != NULL)
    {
        if (pNode1->val <= pNode2->val)
        {
            pCurNode->next = pNode1;
            pCurNode = pNode1;
            pNode1 = pNode1->next;
        }
        else
        {
            pCurNode->next = pNode2;
            pCurNode = pNode2;
            pNode2 = pNode2->next;
        }
    }
    while (NULL != pNode1)
    {
        pCurNode->next = pNode1;
        pCurNode = pNode1;
        pNode1 = pNode1->next;
    }
    while (NULL != pNode2)
    {
        pCurNode->next = pNode2;
        pCurNode = pNode2;
        pNode2 = pNode2->next;
    }
    return pNewHead;
}
// @lc code=end

