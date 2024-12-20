/**
 * @file 637. Average of Levels in Binary Tree(easy)-DFS法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-20
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
	vector<double> averageOfLevels(TreeNode *root)
	{
		vector<double> res;
		memset(levelCount, 0, sizeof(levelCount));
		memset(levelSum, 0, sizeof(levelSum));
		maxLevelIdx = 0;
		dfs(root, 0);
		res.resize(maxLevelIdx + 1);
		for (int i = 0; i <= maxLevelIdx; i++)
		{
			res[i] = levelSum[i] / levelCount[i];
		}
		return res;
	}

private:
	int levelCount[1000];
	double levelSum[1000];
	int maxLevelIdx;

	void dfs(TreeNode *node, int levelIdx)
	{
		if (node == nullptr) { return; }
		maxLevelIdx = max(maxLevelIdx, levelIdx);
		++levelCount[levelIdx];
		levelSum[levelIdx] += node->val;
		dfs(node->left, levelIdx + 1);
		dfs(node->right, levelIdx + 1);
	}
};
