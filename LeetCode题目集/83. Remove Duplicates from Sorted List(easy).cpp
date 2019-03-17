/*
 @Date    : 2019-02-19 22:19:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *f = head, *b = head->next;
        while (b != NULL)
        {
            if (f->val == b->val)
            {
                ListNode *temp = b;
                f->next = b->next;
                delete temp;
            }
            else
                f = b;
            b = f->next;
        }
        return head;
    }
};

