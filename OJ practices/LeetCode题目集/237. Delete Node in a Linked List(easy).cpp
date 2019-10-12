/*
 * @Author: SourDumplings
 * @Date: 2019-08-28 12:36:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * 
 * 这道题实际上是删除node这个结点，将node的下一个结点的值赋值给node再删除node的下一个结点即可
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
    void deleteNode(ListNode *node)
    {
        if (!node || !node->next)
        {
            return;
        }

        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        delete p;
    }
};
