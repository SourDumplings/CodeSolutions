/**
 * @file 138. Copy List with Random Pointer(medium) -哈希表.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-26
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 整体思路是将每个节点分裂，即 A->B->C 变为 A->A'->B->B'->C->C'
 * A' 为新链表的头节点，random 指针为原来的节点所指向的节点的下一个
 * 这样便节省了空间，无需哈希表
 * 时间复杂度 O(n)，空间复杂度 O(1)
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

		Node* p = head;
		while (p)
		{
			Node* tempNode	 = new Node(p->val);
			tempNode->next	 = p->next;
			tempNode->random = p->random;
			p->next			 = tempNode;
			p				 = tempNode->next;
		}

		Node* newHead = head->next;
		p			  = head;
		Node* q		  = newHead;
		while (p)
		{
			if (p->random) { q->random = p->random->next; }
			if (q->next) { q = q->next->next; }
			p = p->next->next;
		}

		q = newHead;
		p = head;
		while (q)
		{
			p->next = p->next->next;
			p		= p->next;

			if (q->next) { q->next = q->next->next; }
			q = q->next;
		}
		return newHead;
	}
};