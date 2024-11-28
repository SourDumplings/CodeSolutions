/**
 * @file 82. Remove Duplicates from Sorted List II(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-28
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
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
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* tempHead = new ListNode(0, head);
		ListNode* f		   = tempHead;
		ListNode* p		   = head;
		while (f && f->next)
		{
			p = f->next;
			while (p->next && p->next->val == p->val)
			{
				p = p->next;
			}
			if (p != f->next) { f->next = p->next; }
			else { f = f->next; }
		}
		ListNode* ret = tempHead->next;
		delete tempHead;
		return ret;
	}
};
