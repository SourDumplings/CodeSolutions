/*
 * @Autor: SourDumplings
 * @Date: 2019-10-22 20:36:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root)
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val < val)
            {
                return searchBST(root->right, val);
            }
            else
            {
                return searchBST(root->left, val);
            }
        }
        else
        {
            return nullptr;
        }
    }
};