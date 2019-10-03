/*
 * @Autor: SourDumplings
 * @Date: 2019-10-02 11:17:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            levelOrder(root, [&](TreeNode *node) { sum += node->val; });
            levelOrder(root, [&](TreeNode *node) {
                sum -= node->val;
                node->val += sum;
            });
        }
        return root;
    }

    template <typename F>
    void levelOrder(TreeNode *root, const F &f)
    {
        stack<TreeNode *> S;
        while (true)
        {
            TreeNode *leftMost = root;
            while (leftMost)
            {
                S.push(leftMost);
                leftMost = leftMost->left;
            }
            if (S.empty())
            {
                break;
            }
            leftMost = S.top();
            S.pop();
            f(leftMost);
            root = leftMost->right;
        }
    }
};