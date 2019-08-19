/*
 * @Author: SourDumplings
 * @Date: 2019-08-19 13:10:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = new ListNode(0);
        ListNode *p = head;
        while (p)
        {
            ListNode *q = p->next;
            p->next = temp->next;
            temp->next = p;
            p = q;
        }
        head = temp->next;
        delete temp;
        return head;
    }
};