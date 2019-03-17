/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/symmetric-tree/
 * @Date: 2019-03-01 13:12:27
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if (!t1 && !t2)
            {
                continue;
            }
            else if (t1 && !t2 || !t1 && t2 || t1->val != t2->val)
            {
                return false;
            }
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};