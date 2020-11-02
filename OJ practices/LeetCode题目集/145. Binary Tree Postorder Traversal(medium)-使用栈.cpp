/*
 * @Author: SourDumplings
 * @Date: 2020-11-02 22:27:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> S;
        TreeNode *p = root, *lastVisited = nullptr;
        vector<int> res;
        while (p || !S.empty())
        {
            if (p)
            {
                S.push(p);
                p = p->left;
            }
            else
            {
                p = S.top();
                if (p->right && p->right != lastVisited)
                {
                    p = p->right;
                    S.push(p);
                    p = p->left;
                }
                else
                {
                    res.push_back(p->val);
                    lastVisited = p;
                    p = nullptr;
                    S.pop();
                }
            }
        }
        return res;
    }
};