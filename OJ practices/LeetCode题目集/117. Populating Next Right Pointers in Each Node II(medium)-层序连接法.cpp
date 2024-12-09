/**
 * @file 117. Populating Next Right Pointers in Each Node II(medium)-层序连接法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 可以利用 next 指针来进行层序遍历，就不需要额外的队列了，空间复杂度为 O(1)，时间复杂度还是 O(n)
 */

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
	Node* connect(Node* root)
	{
		Node* start = root;
		while (start)
		{
			Node* lastNode		 = NULL;
			Node* nextLevelStart = NULL;
			for (Node* p = start; p; p = p->next)
			{
				if (p->left) { handle(lastNode, p->left, nextLevelStart); }
				if (p->right) { handle(lastNode, p->right, nextLevelStart); }
			}
			start = nextLevelStart;
		}
		return root;
	}

private:
	void handle(Node*& lastNode, Node* thisNode, Node*& nextLevelStart)
	{
		if (lastNode) { lastNode->next = thisNode; }
		if (nextLevelStart == NULL) { nextLevelStart = thisNode; }
		lastNode = thisNode;
	}
};