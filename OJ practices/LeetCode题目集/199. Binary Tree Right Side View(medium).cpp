/**
 * @file 199. Binary Tree Right Side View(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 本质上是找每一层的最有结点
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
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> res;
		if (root == nullptr) { return res; }

		vector<TreeNode *> thisLevel;
		thisLevel.push_back(root);
		while (!thisLevel.empty())
		{
			vector<TreeNode *> nextLevel;
			for (TreeNode *node : thisLevel)
			{
				if (node->left) { nextLevel.push_back(node->left); }
				if (node->right) { nextLevel.push_back(node->right); }
			}
			res.push_back(thisLevel.back()->val);
			thisLevel = std::move(nextLevel);
		}
		return res;
	}
};