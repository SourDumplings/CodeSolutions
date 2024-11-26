/**
 * @file 19. Remove Nth Node From End of List(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-27
 *
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 双指针法，两个指针距离 n 即可
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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* tempHead = new ListNode(0, head);
		ListNode* l		   = tempHead;
		ListNode* r		   = head;

		int count = 1;
		while (r->next)
		{
			if (count < n) { ++count; }
			else { l = l->next; }
			r = r->next;
		}
		l->next		  = l->next->next;
		ListNode* ret = tempHead->next;
		delete tempHead;
		return ret;
	}
};