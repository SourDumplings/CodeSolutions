/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * @Date: 2019-03-07 20:42:14
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
    const int MAX = 99999;
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else if (!root->left && !root->right)
        {
            return 1;
        }
        else
        {
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            if (l == 0)
            {
                l = MAX;
            }
            if (r == 0)
            {
                r = MAX;
            }
            return min(l, r) + 1;
        }
    }
};