/*
 * @Author: SourDumplings
 * @Date: 2020-12-02 20:08:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *res = nullptr;
        ListNode *p = headA;
        while (p)
        {
            p->val *= -1;
            p = p->next;
        }
        p = headB;
        while (p)
        {
            if (p->val < 0)
            {
                res = p;
                break;
            }
            p = p->next;
        }
        p = headA;
        while (p)
        {
            p->val *= -1;
            p = p->next;
        }
        return res;
    }
};