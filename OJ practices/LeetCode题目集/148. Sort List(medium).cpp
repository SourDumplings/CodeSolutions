/*
 * @Author: SourDumplings
 * @Date: 2020-11-19 21:02:18
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/sort-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *h, *h1, *h2, *pre, *res;
        h = head;
        int length = 0, intv = 1;
        while (h)
        {
            h = h->next;
            length++;
        }
        res = new ListNode(0);
        res->next = head;
        while (intv < length)
        {
            pre = res;
            h = res->next;
            while (h)
            {
                int i = intv;
                h1 = h;
                while (i > 0 && h)
                {
                    h = h->next;
                    i--;
                }
                if (i > 0)
                { break; }
                i = intv;
                h2 = h;
                while (i > 0 && h)
                {
                    h = h->next;
                    i--;
                }
                int c1 = intv, c2 = intv - i;
                while (c1 > 0 && c2 > 0)
                {
                    if (h1->val < h2->val)
                    {
                        pre->next = h1;
                        h1 = h1->next;
                        c1--;
                    }
                    else
                    {
                        pre->next = h2;
                        h2 = h2->next;
                        c2--;
                    }
                    pre = pre->next;
                }
                pre->next = c1 == 0 ? h2 : h1;
                while (c1 > 0 || c2 > 0)
                {
                    pre = pre->next;
                    c1--;
                    c2--;
                }
                pre->next = h;
            }
            intv *= 2;
        }
        return res->next;
    }
};