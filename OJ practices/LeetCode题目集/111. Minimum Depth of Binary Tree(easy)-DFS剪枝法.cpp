/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * @Date: 2019-03-07 20:56:10
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
    const int MAX = 99999;
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int minD = MAX;
        dfs(root, 1, minD);
        return minD;
    }
    void dfs(TreeNode *s, int nowD, int &minD)
    {
        if (!s->left && !s->right)
        {
            if (nowD < minD)
            {
                minD = nowD;
            }
        }
        else if (nowD < minD)
        {
            if (s->left)
            {
                dfs(s->left, nowD + 1, minD);
            }
            if (s->right)
            {
                dfs(s->right, nowD + 1, minD);
            }
        }
        return;
    }
};