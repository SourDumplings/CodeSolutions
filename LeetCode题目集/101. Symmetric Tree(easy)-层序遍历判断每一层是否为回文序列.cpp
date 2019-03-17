/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/symmetric-tree/
 * @Date: 2019-02-28 18:44:42
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
        queue<TreeNode *> q;
        q.push(root);

        while (true)
        {
            deque<TreeNode *> dq;
            while (!q.empty())
            {
                dq.push_back(q.front());
                q.pop();
            }
            if (!plalindrome(dq))
            {
                return false;
            }
            else
            {
                bool flag = true;
                while (!dq.empty())
                {
                    TreeNode *temp = dq.front();
                    if (temp)
                    {
                        flag = false;
                        q.push(temp->left);
                        q.push(temp->right);
                    }
                    dq.pop_front();
                }
                if (flag)
                {
                    break;
                }
            }
        }
        return true;
    }

    bool plalindrome(const deque<TreeNode *> &dq)
    {
        int n = dq.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (dq[i] && !dq[n - i - 1] || dq[n - i - 1] && !dq[i] ||
                dq[i] && dq[n - i - 1] && dq[i]->val != dq[n - i - 1]->val)
            {
                return false;
            }
        }
        return true;
    }
};