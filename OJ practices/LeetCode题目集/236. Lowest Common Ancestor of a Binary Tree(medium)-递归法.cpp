/**
 * @file 236. Lowest Common Ancestor of a Binary Tree(medium)-递归法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-18
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 如果 p、q 分别在 node 的左右子树（或本身）中，那 node 就是 LCA
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		hasChildren(root, p, q);
		return m_lca;
	}

private:
	TreeNode *m_lca = nullptr;

	bool hasChildren(TreeNode *node, TreeNode *p, TreeNode *q)
	{
		if (node == nullptr) { return false; }
		bool lHasChildren = hasChildren(node->left, p, q);
		bool rHasChildren = hasChildren(node->right, p, q);
		if (lHasChildren && rHasChildren ||
			(node == p || node == q) && (lHasChildren || rHasChildren))
		{
			m_lca = node;
		}
		return node == p || node == q || lHasChildren || rHasChildren;
	}
};