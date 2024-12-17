/**
 * @file 222. Count Complete Tree Nodes(medium)-寻找满二叉子树法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/count-complete-tree-nodes/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 对于完全二叉树的左右子树来说，只可能有一个子树是不满的
 * 思路就是逐步找满二叉子树，直接计算得到结果，时间复杂度 O(logn)
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
	int countNodes(TreeNode *root)
	{
		if (root == nullptr) { return 0; }

		int lHeight = 0;
		TreeNode *p = root;
		while (p)
		{
			++lHeight;
			p = p->left;
		}
		p			= root;
		int rHeight = 0;
		while (p)
		{
			++rHeight;
			p = p->right;
		}
		if (lHeight == rHeight) { return pow(2, lHeight) - 1; }
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};