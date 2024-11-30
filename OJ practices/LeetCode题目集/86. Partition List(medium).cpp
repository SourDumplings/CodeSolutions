/**
 * @file 86. Partition List(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/partition-list/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-30
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
	ListNode *partition(ListNode *head, int x) {
		ListNode *tempHead1 = new ListNode(0, head);
		ListNode *f1 = tempHead1;
		ListNode *tempHead2 = new ListNode(0);
		ListNode *f2 = tempHead2;
		while (f1->next)
		{
			ListNode *p = f1->next;
			if (p->val < x)
			{
				f1->next = p->next;
				p->next = nullptr;
				f2->next = p;
				f2 = p;
			}
			else
			{
				f1 = f1->next;
			}
		}
		f2->next = tempHead1->next;
		head = tempHead2->next;
		delete tempHead1;
		delete tempHead2;
		return head;
	}
};
