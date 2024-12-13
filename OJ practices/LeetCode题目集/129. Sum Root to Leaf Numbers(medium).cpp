/**
 * @file 129. Sum Root to Leaf Numbers(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-13
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
	int sumNumbers(TreeNode *root)
	{
		if (root == nullptr) { return 0; }

		solve(root->val, root);
		return res;
	}

private:
	void solve(int nowSum, TreeNode *root)
	{
		if (root->left == nullptr && root->right == nullptr) { res += nowSum; }

		if (root->left) { solve(nowSum * 10 + root->left->val, root->left); }
		if (root->right) { solve(nowSum * 10 + root->right->val, root->right); }
	}

	int res = 0;
};