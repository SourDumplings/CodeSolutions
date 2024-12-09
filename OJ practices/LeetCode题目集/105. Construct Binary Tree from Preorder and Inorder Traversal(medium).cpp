/**
 * @file 105. Construct Binary Tree from Preorder and Inorder Traversal(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan-v2&envId=top-interview-150
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		size_t n = preorder.size();
		return buildTree(preorder, 0, n, inorder, 0, n);
	}

private:
	TreeNode *buildTree(
		const vector<int> &pre,
		size_t preB,
		size_t preE,
		const vector<int> &in,
		size_t inB,
		size_t inE
	)
	{
		if (preB == preE) { return nullptr; }
		int rootVal	   = pre[preB];
		TreeNode *root = new TreeNode(rootVal);
		for (size_t i = inB; i < inE; i++)
		{
			if (in[i] == rootVal)
			{
				root->left	= buildTree(pre, preB + 1, preB + 1 + i - inB, in, inB, i);
				root->right = buildTree(pre, preB + 1 + i - inB, preE, in, i + 1, inE);
				break;
			}
		}
		return root;
	}
};