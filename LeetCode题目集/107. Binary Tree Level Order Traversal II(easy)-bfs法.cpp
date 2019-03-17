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
		queue<pair<TreeNode *, int>> q;
		q.push(make_pair(root, 0));

		if (root == nullptr)
		{
			res.clear();
			return res;
		}

		while (!q.empty())
		{
			pair<TreeNode *, int> p = q.front();
			TreeNode *node = p.first;
			int level = p.second;
			q.pop();
			res[level].push_back(node->val);
			if (node->left)
			{
				q.push(make_pair(node->left, level + 1));
			}
			if (node->right)
			{
				q.push(make_pair(node->right, level + 1));
			}
		}

		for (auto it = res.begin(); it < res.end(); it++)
		{
			if (it->empty())
			{
				res.erase(it, res.end());
			}
		}

		reverse(res.begin(), res.end());

		return res;
	}
};