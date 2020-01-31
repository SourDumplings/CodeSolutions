/*
 * @Author: SourDumplings
 * @Date: 2019-10-10 07:57:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1)
        {
            if (t2)
            {
                t1->val += t2->val;
            }
        }
        else if (t2)
        {
            t1 = new TreeNode(t2->val);
        }

        if (t1 && t2)
        {
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
        }

        return t1;
    }
};