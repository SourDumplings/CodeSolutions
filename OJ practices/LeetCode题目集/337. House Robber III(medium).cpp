/*
 * @Author: SourDumplings
 * @Date: 2021-04-05 21:03:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/house-robber-iii/
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
    unordered_map<TreeNode *, int> f, g; // 分别代表选该结点与不选该结点时，其子树的结果

    void dfs(TreeNode *node)
    {
        if (node->left)
        {
            dfs(node->left);
        }
        if (node->right)
        {
            dfs(node->right);
        }
        f[node] = g[node->left] + g[node->right] + node->val;
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }
public:
    int rob(TreeNode *root)
    {
        if (root)
        {
            dfs(root);
        }
        return max(f[root], g[root]);
    }
};
