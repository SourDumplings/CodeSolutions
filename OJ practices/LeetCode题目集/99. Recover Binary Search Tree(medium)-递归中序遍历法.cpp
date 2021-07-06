/*
 * @Author: SourDumplings
 * @Date: 2021-07-06 09:46:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/recover-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    vector<int> in;
    int idx = 0;

    void inorder_traversal(TreeNode *node)
    {
        if (node)
        {
            inorder_traversal(node->left);
            in.push_back(node->val);
            inorder_traversal(node->right);
        }
    }

    void re_inorder_traversal(TreeNode *node)
    {
        if (node)
        {
            re_inorder_traversal(node->left);
            node->val = in[idx++];
            re_inorder_traversal(node->right);
        }
    }
public:
    void recoverTree(TreeNode *root)
    {
        inorder_traversal(root);
        sort(in.begin(), in.end());
        re_inorder_traversal(root);
    }
};