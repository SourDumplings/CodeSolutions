/*
 * @Autor: SourDumplings
 * @Date: 2019-10-12 07:49:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> in;
        inOrder(root, in);
        int n = in.size();
        for (int i = 0; i < n; i++)
        {
            int a = in[i];
            if (i < n - 1 && binary_search(in.begin() + i + 1, in.begin() + n, k - a))
            {
                return true;
            }
        }
        return false;
    }

    void inOrder(TreeNode *root, vector<int> &res)
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
            res.push_back(leftMost->val);
            root = leftMost->right;
        }
    }
};