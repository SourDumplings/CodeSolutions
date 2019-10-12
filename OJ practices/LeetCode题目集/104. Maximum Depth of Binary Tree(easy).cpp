/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * @Date: 2019-03-03 17:02:38
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
    int maxDepth(TreeNode *root)
    {
        return getHeight(root);
    }
    int getHeight(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }
};