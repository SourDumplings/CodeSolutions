/*
 * @Author: SourDumplings
 * @Date: 2019-10-16 16:32:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-univalue-path/
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
private:
    int res;

public:
    int longestUnivaluePath(TreeNode *root)
    {
        res = 0;
        arrowLength(root);
        return res;
    }

    int arrowLength(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if (node->left && node->val == node->left->val)
        {
            arrowLeft = left + 1;
        }
        if (node->right && node->val == node->right->val)
        {
            arrowRight = right + 1;
        }
        if (arrowLeft + arrowRight > res)
        {
            res = arrowLeft + arrowRight;
        }
        return max(arrowLeft, arrowRight);
    }
};