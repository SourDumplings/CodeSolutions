/*
 * @Author: SourDumplings
 * @Date: 2021-03-30 18:43:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/odd-even-linked-list/
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *tempEmptyHead = new ListNode;
        ListNode *f = head;
        if (!f)
        {
            return nullptr;
        }
        ListNode *p = f->next;
        ListNode *tempR = tempEmptyHead;
        while (p)
        {
            f->next = p->next;
            p->next = nullptr;
            tempR->next = p;
            tempR = p;
            if (f->next)
            {
                f = f->next;
                p = f->next;
            }
            else
            {
                break;
            }
        }
        f->next = tempEmptyHead->next;
        delete tempEmptyHead;
        return head;
    }
};