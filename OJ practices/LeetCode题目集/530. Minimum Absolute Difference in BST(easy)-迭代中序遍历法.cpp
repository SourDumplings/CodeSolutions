/*
 * @Author: SourDumplings
 * @Date: 2019-09-30 19:05:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int res = __INT32_MAX__;
    bool isFirst = true;
    int lastVal = 0;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        levelOrder(root);
        return res;
    }

    void levelOrder(TreeNode *root)
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
            visit(leftMost);
            root = leftMost->right;
        }
    }

    void visit(TreeNode *node)
    {
        int val = node->val;
        if (isFirst)
        {
            isFirst = false;
        }
        else if (val - lastVal < res)
        {
            res = val - lastVal;
        }
        lastVal = val;
    }
};