/*
 * @Author: SourDumplings
 * @Date: 2020-11-18 22:00:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/insertion-sort-list/
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *tempHead = new ListNode(0);
        ListNode *p = head;
        while (p != nullptr)
        {
            ListNode *f = tempHead;
            while (f->next != nullptr && f->next->val < p->val)
            {
                f = f->next;
            }
            ListNode *tempNode = f->next;
            f->next = p;
            ListNode *nextNode = p->next;
            p->next = tempNode;
            p = nextNode;
        }
        head = tempHead->next;
        delete tempHead;
        return head;
    }
};