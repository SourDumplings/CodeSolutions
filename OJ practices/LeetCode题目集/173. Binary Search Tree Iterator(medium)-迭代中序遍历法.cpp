/**
 * @file 173. Binary Search Tree Iterator(medium)-迭代中序遍历法.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-12-16
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
class BSTIterator
{
public:
	BSTIterator(TreeNode *root) { pushAllLeftChildren(root); }

	int next()
	{
		TreeNode *leftMost = m_S.top();
		m_S.pop();
		if (leftMost->right) { pushAllLeftChildren(leftMost->right); }
		return leftMost->val;
	}

	bool hasNext() { return !m_S.empty(); }

private:
	stack<TreeNode *> m_S;

	void pushAllLeftChildren(TreeNode *node)
	{
		while (node)
		{
			m_S.push(node);
			node = node->left;
		}
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */