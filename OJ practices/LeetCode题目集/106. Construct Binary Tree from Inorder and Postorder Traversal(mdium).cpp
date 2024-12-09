/**
 * @file 106. Construct Binary Tree from Inorder and Postorder Traversal(mdium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=study-plan-v2&envId=top-interview-150
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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		size_t n = inorder.size();
		return buildTree(inorder, 0, n, postorder, 0, n);
	}

private:
	TreeNode *buildTree(
		const vector<int> &in,
		size_t inB,
		size_t inE,
		const vector<int> &post,
		size_t postB,
		size_t postE
	)
	{
		if (inB == inE) { return nullptr; }
		int rootVal	   = post[postE - 1];
		TreeNode *root = new TreeNode(rootVal);
		for (size_t i = inB; i != inE; ++i)
		{
			if (in[i] == rootVal)
			{
				root->left	= buildTree(in, inB, i, post, postB, postB + i - inB);
				root->right = buildTree(in, i + 1, inE, post, postB + i - inB, postE - 1);
			}
		}
		return root;
	}
};