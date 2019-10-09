/*
 * @Autor: SourDumplings
 * @Date: 2019-10-09 21:21:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/construct-string-from-binary-tree/
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
    string tree2str(TreeNode *t)
    {
        string res;
        if (t)
        {
            preOrder(t, res);
        }
        return res;
    }

    void preOrder(TreeNode *t, string &res)
    {
        res += to_string(t->val);
        if (t->right || t->left)
        {
            res += '(';
        }
        if (t->left)
        {
            preOrder(t->left, res);
        }
        if (t->right || t->left)
        {
            res += ')';
        }
        if (t->right)
        {
            res += '(';
            preOrder(t->right, res);
            res += ')';
        }
    }
};