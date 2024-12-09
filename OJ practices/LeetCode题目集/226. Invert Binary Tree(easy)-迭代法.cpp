/**
 * @file 226. Invert Binary Tree(easy)-迭代法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	TreeNode *invertTree(TreeNode *root)
	{
		if (root == nullptr) { return nullptr; }

		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();
			swap(node->left, node->right);
			if (node->left) { q.push(node->left); }
			if (node->right) { q.push(node->right); }
		}
		return root;
	}
};