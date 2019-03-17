/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * @Date: 2019-03-04 17:36:39
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
	vector<vector<int>> levelOrderBottom(TreeNode *root)
	{
		vector<vector<int>> res(1000);
		dfs(root, 0, res);
		for (auto it = res.begin(); it < res.end(); it++)
		{
			if (it->empty())
			{
				res.erase(it, res.end());
				break;
			}
		}
		reverse(res.begin(), res.end());

		return res;
	}

	void dfs(TreeNode *node, int level, vector<vector<int>> &res)
	{
		if (node)
		{
			res[level].push_back(node->val);
			dfs(node->left, level + 1, res);
			dfs(node->right, level + 1, res);
		}
	}
};