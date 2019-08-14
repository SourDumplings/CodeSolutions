/*
 * @Author: SourDumplings
 * @Date: 2019-08-14 08:30:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *f = head, *p = head;
        while (p && p->val == val)
        {
            ListNode *temp = p;
            p = p->next;
            delete temp;
        }
        ListNode *h = p;
        f = p;
        if (f)
        {
            p = p->next;
        }
        while (p)
        {
            if (p->val == val)
            {
                f->next = p->next;
                delete p;
                p = f->next;
            }
            else
            {
                f = p;
                p = p->next;
            }
        }
        return h;
    }
};
