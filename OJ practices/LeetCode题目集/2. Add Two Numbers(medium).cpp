/**
 * @file 2. Add Two Numbers(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-14
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		bool isCarryOver = false;
		ListNode* p1	 = l1;
		ListNode* p2	 = l2;
		ListNode* h		 = new ListNode(0);
		ListNode* p		 = h;
		while (p1 && p2)
		{
			p->next		= new ListNode(0);
			p			= p->next;
			p->val		= p1->val + p2->val + (isCarryOver ? 1 : 0);
			isCarryOver = false;
			if (10 <= p->val)
			{
				isCarryOver	 = true;
				p->val		%= 10;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1)
		{
			p->next		= new ListNode(0);
			p			= p->next;
			p->val		= p1->val + (isCarryOver ? 1 : 0);
			isCarryOver = false;
			if (10 <= p->val)
			{
				isCarryOver	 = true;
				p->val		%= 10;
			}
			p1 = p1->next;
		}
		while (p2)
		{
			p->next		= new ListNode(0);
			p			= p->next;
			p->val		= p2->val + (isCarryOver ? 1 : 0);
			isCarryOver = false;
			if (10 <= p->val)
			{
				isCarryOver	 = true;
				p->val		%= 10;
			}
			p2 = p2->next;
		}
		if (isCarryOver) { p->next = new ListNode(1); }

		p = h;
		h = p->next;
		delete p;
		return h;
	}
};
