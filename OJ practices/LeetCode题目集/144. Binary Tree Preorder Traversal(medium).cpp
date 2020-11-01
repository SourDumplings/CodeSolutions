/*
 * @Author: SourDumplings
 * @Date: 2020-11-01 18:53:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode*> S;
        while (true)
        {
            TreeNode *leftMost = root;
            while (leftMost != nullptr)
            {
                res.push_back(leftMost->val);
                if (leftMost->right != nullptr)
                {
                    S.push(leftMost->right);
                }
                leftMost = leftMost->left;
            }
            if (S.empty())
            {
                break;
            }
            root = S.top();
            S.pop();
        }
        return res;
    }
};