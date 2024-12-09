/**
 * @file 117. Populating Next Right Pointers in Each Node II(medium)-层序遍历法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * @version 1.0.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
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
		if (root == nullptr) { return nullptr; }

		vector<Node*> thisLevelNodes;
		thisLevelNodes.push_back(root);
		while (!thisLevelNodes.empty())
		{
			size_t n = thisLevelNodes.size();
			vector<Node*> nextLevelNodes;
			for (size_t i = 0; i < n; ++i)
			{
				Node* node = thisLevelNodes[i];
				if (i < n - 1) { node->next = thisLevelNodes[i + 1]; }
				if (node->left) { nextLevelNodes.push_back(node->left); }
				if (node->right) { nextLevelNodes.push_back(node->right); }
			}
			thisLevelNodes = std::move(nextLevelNodes);
		}
		return root;
	}
};