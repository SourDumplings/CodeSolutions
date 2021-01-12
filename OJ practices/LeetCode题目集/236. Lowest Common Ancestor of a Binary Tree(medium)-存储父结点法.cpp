/*
 * @Author: SourDumplings
 * @Date: 2021-01-12 10:32:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * 
 * 参考：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/
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
    unordered_map<int, TreeNode *> f;
    unordered_map<int, bool> visited;

    void pre_order(TreeNode *node)
    {
        if (node->left)
        {
            f[node->left->val] = node;
            pre_order(node->left);
        }
        if (node->right)
        {
            f[node->right->val] = node;
            pre_order(node->right);
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return nullptr;
        }
        f[root->val] = nullptr;
        pre_order(root);
        while (p)
        {
            visited[p->val] = true;
            p = f[p->val];
        }
        while (q)
        {
            if (visited[q->val])
            {
                return q;
            }
            q = f[q->val];
        }
        return nullptr;
    }
};