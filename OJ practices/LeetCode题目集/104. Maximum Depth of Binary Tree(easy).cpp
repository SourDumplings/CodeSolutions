/**
 * @file 104. Maximum Depth of Binary Tree(easy).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-03
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
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr) { return 0; }
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};