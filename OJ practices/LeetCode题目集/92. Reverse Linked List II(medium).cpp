/**
 * @file 92. Reverse Linked List II(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-26
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
	ListNode* reverseBetween(ListNode* head, int left, int right)
	{
		ListNode* tempHead = new ListNode(0, head);
		int count		   = 1;
		ListNode* f		   = tempHead;
		ListNode* revHead  = tempHead;

		while (f->next)
		{
			ListNode* p = f->next;
			if (count < left) { f = p; }
			else if (count == left)
			{
				revHead = f;
				f		= p;
			}
			else if (left < count && count <= right)
			{
				f->next		  = p->next;
				p->next		  = revHead->next;
				revHead->next = p;
			}
			else { break; }

			++count;
		}
		ListNode* ret = tempHead->next;
		delete tempHead;
		return ret;
	}
};