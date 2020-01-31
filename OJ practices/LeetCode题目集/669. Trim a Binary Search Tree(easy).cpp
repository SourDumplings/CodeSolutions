/*
 * @Author: SourDumplings
 * @Date: 2019-10-13 14:16:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/trim-a-binary-search-tree/
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root)
        {
            int v = root->val;
            if (v < L)
            {
                return trimBST(root->right, L, R);
            }
            else if (R < v)
            {
                return trimBST(root->left, L, R);
            }
            else
            {
                root->left = trimBST(root->left, L, R);
                root->right = trimBST(root->right, L, R);
            }
        }
        return root;
    }
};