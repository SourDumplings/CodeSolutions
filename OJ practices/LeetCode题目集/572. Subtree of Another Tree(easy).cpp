/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 18:22:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/subtree-of-another-tree/
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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (isEqual(s, t))
        {
            return true;
        }
        else
        {
            if (s)
            {
                return isSubtree(s->left, t) || isSubtree(s->right, t);
            }
            else
            {
                return !t;
            }
        }
    }

    bool isEqual(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        else if (!a && b || !b && a)
        {
            return false;
        }
        else
        {
            return a->val == b->val && isEqual(a->left, b->left) && isEqual(a->right, b->right);
        }
    }
};