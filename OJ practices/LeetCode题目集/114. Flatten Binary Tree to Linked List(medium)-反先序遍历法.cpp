/**
 * @file 114. Flatten Binary Tree to Linked List(medium)-先序遍历法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-10
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
	void flatten(TreeNode *root)
	{
		if (root == nullptr) { return; }
		flatten(root->right);
		flatten(root->left);
		root->right	   = lastNode;
		lastNode	   = root;
		lastNode->left = nullptr;
	}

private:
	TreeNode *lastNode = nullptr;
};