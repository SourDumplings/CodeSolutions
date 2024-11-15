/**
 * @file 21. Merge Two Sorted Lists(easy).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-15
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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* h	 = new ListNode(0);
		ListNode* p1 = list1;
		ListNode* p2 = list2;
		ListNode* p	 = h;
		while (p1 && p2)
		{
			p->next = new ListNode(0);
			p		= p->next;
			if (p1->val < p2->val)
			{
				p->val = p1->val;
				p1	   = p1->next;
			}
			else
			{
				p->val = p2->val;
				p2	   = p2->next;
			}
		}
		while (p1)
		{
			p->next = new ListNode(0);
			p		= p->next;
			p->val	= p1->val;
			p1		= p1->next;
		}
		while (p2)
		{
			p->next = new ListNode(0);
			p		= p->next;
			p->val	= p2->val;
			p2		= p2->next;
		}
		p = h;
		h = h->next;
		delete p;
		return h;
	}
};