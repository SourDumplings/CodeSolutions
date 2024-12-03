/**
 * @file 100. Same Tree(easy).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150
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
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		return (p == nullptr && q == nullptr) ||
			(p && q && (p->val == q->val) && isSameTree(p->left, q->left) &&
			 isSameTree(p->right, q->right));
	}
};