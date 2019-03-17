/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 * @Date: 2019-03-01 13:25:58
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
    bool isSymmetric(TreeNode *root)
    {
        bool ret = true;
        if (root)
        {
            ret = equal(root->left, root->right);
        }
        return ret;
    }

    bool equal(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2)
        {
            return true;
        }
        else if (t1 && !t2 || !t1 && t2 || t1->val != t2->val)
        {
            return false;
        }
        else
        {
            return equal(t1->left, t2->right) && equal(t1->right, t2->left);
        }
    }
};