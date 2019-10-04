/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 09:57:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int ans = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root)
        {
            ans = 1;
            depth(root);
            return ans - 1;
        }
        else
        {
            return 0;
        }
    }

    int depth(TreeNode *p)
    {
        if (!p)
        {
            return 0;
        }
        int l = depth(p->left);
        int r = depth(p->right);
        ans = l + r + 1 > ans ? l + r + 1 : ans;
        return l > r ? l + 1 : r + 1;
    }
};