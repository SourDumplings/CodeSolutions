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
    TreeNode *res = nullptr;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return false;
        }

        bool lContainsOne = dfs(root->left, p, q);
        bool rContainsOne = dfs(root->right, p, q);
        if ((lContainsOne && rContainsOne)
            || ((root->val == p->val || root->val == q->val)
                && (lContainsOne || rContainsOne)))
        {
            res = root;
        }
        return lContainsOne || rContainsOne || root->val == p->val
            || root->val == q->val;
    }
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return res;
    }
};