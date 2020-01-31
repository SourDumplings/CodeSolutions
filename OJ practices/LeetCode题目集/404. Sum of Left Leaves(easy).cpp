/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 08:05:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int res = 0;
        doSumOfLeftLeaves(root, nullptr, res);
        return res;
    }

    void doSumOfLeftLeaves(TreeNode *x, TreeNode *p, int &res)
    {
        if (x)
        {
            if (!x->left && !x->right)
            {
                if (p && x == p->left)
                {
                    res += x->val;
                }
            }
            else
            {
                if (x->left)
                {
                    doSumOfLeftLeaves(x->left, x, res);
                }
                if (x->right)
                {
                    doSumOfLeftLeaves(x->right, x, res);
                }
            }
        }
    }
};