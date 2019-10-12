/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/path-sum/
 * @Date: 2019-03-08 21:38:19
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return false;
        }
        int nowSum = root->val;
        return dfs(root, nowSum, sum);
    }

    bool dfs(TreeNode *root, int nowSum, int sum)
    {
        if (!root->left && !root->right && nowSum == sum)
        {
            return true;
        }
        else if (root->left && dfs(root->left, nowSum + root->left->val, sum) ||
                 root->right && dfs(root->right, nowSum + root->right->val, sum))
        {
            return true;
        }
        return false;
    }
};