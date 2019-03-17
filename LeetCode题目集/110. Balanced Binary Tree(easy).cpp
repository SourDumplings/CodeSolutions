/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/balanced-binary-tree/
 * @Date: 2019-03-06 18:05:46
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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        else if (abs(get_height(root->left) - get_height(root->right)) >= 2)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int get_height(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return max(get_height(node->left), get_height(node->right)) + 1;
        }
    }
};