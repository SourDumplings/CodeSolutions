/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/linked-list-cycle/
 * @Date: 2019-04-02 12:00:02
 * 
 * 用两个指针，一个一次前进两个，一个前进一次一个，若是有环则快的会和慢的相遇
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
	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head, *slow = head;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
			}
			else
			{
				break;
			}
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}
};