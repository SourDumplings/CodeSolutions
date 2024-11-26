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

		if (m_cachedNodes.find(head) == m_cachedNodes.end())
		{
			Node* newHead		= new Node(head->val);
			m_cachedNodes[head] = newHead;
			newHead->next		= copyRandomList(head->next);
			newHead->random		= copyRandomList(head->random);
		}
		return m_cachedNodes.at(head);
	}

private:
	unordered_map<Node*, Node*> m_cachedNodes;
};