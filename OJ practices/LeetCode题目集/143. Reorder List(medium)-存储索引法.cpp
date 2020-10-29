/*
 * @Author: SourDumplings
 * @Date: 2020-10-29 17:23:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reorder-list/
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        vector<ListNode*> v;
        ListNode *p = head;
        while (p)
        {
            v.push_back(p);
            p = p->next;
        }
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            v[i]->next = v[j];
            ++i;
            if (i == j)
            {
                break;
            }
            v[j]->next = v[i];
            --j;
        }
        v[i]->next = nullptr;
    }
};