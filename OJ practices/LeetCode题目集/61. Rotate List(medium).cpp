/**
 * @file 61. Rotate List(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 *
 * 思路是将链表闭合成一个环，再在特定位置断开即可
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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr) { return nullptr; }

		int n		= 1;
		ListNode* p = head;
		while (p->next)
		{
			p = p->next;
			++n;
		}
		p->next	   = head;
		int count  = 0;
		k		  %= n;
		while (true)
		{
			if (count + 1 == n - k)
			{
				ListNode* temp = head->next;
				head->next	   = nullptr;
				head = temp;
				break;
			}

			head = head->next;
			++count;
		}
		return head;
	}
};