/**
 * @file 138. Copy List with Random Pointer(medium) -哈希表.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-26
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 */

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution
{
public:
	Node* copyRandomList(Node* head)
	{
		if (head == nullptr) { return nullptr; }

		int idx = 0;
		Node* p = head;
		unordered_map<Node*, int> idxMap;
		unordered_map<int, Node*> idxMapNew;
		Node* tempHead = new Node(0);
		Node* q		   = tempHead;
		while (p)
		{
			idxMap[p]	   = idx;
			q->next		   = new Node(p->val);
			p			   = p->next;
			q			   = q->next;
			idxMapNew[idx] = q;
			++idx;
		}
		p = head;
		q = tempHead->next;
		while (p)
		{
			Node* r = p->random;

			if (r)
			{
				int idx	  = idxMap[r];
				q->random = idxMapNew[idx];
			}
			p = p->next;
			q = q->next;
		}
		Node* ret = tempHead->next;
		delete tempHead;
		return ret;
	}
};