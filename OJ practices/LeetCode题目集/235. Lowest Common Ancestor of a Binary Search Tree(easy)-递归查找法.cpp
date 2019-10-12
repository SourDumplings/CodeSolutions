/*
 * @Author: SourDumplings
 * @Date: 2019-08-27 20:59:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *res = nullptr;
        search_in_bst(root, p, q, res);
        return res;
    }

    void search_in_bst(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&res)
    {
        if (p->val < root->val)
        {
            if (q->val < root->val)
            {
                search_in_bst(root->left, p, q, res);
            }
            else
            {
                res = root;
            }
        }
        else if (p->val == root->val)
        {
            res = root;
        }
        else
        {
            if (q->val > root->val)
            {
                search_in_bst(root->right, p, q, res);
            }
            else
            {
                res = root;
            }
        }
    }
};