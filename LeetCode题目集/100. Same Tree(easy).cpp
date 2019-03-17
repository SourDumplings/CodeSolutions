/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/same-tree/
 * @Date: 2019-02-27 18:09:46
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return isSameNode(p, q);
    }

    bool isSameNode(TreeNode *p, TreeNode *q)
    {
        if ((!p && !q) || p && q && p->val == q->val && isSameNode(p->left, q->left) && isSameNode(p->right, q->right))
        {
            return true;
        }
        return false;
    }
};