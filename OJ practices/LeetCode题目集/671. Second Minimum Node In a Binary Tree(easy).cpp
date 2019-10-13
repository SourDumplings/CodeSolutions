/*
 * @Autor: SourDumplings
 * @Date: 2019-10-13 20:15:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root || !root->left)
        {
            return -1;
        }
        int m = root->val;
        int l = findSecond(root->left, m);
        int r = findSecond(root->right, m);
        return l < r && l != -1 || r == -1 ? l : r;
    }

    int findSecond(TreeNode *node, int limit)
    {
        int v = node->val;
        if (v > limit)
        {
            return v;
        }
        else if (node->left)
        {
            int l = findSecond(node->left, limit);
            int r = findSecond(node->right, limit);
            return l < r && l != -1 || r == -1 ? l : r;
        }
        return -1;
    }
};