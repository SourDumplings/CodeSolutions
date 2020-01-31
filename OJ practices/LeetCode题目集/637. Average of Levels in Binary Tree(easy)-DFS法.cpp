/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 15:26:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<long long> levelSum;
    vector<int> levelCount;

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        DFS(root, 0);
        vector<double> res;
        int n = levelSum.size();
        res.resize(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = ((double)(levelSum[i])) / levelCount[i];
        }
        return std::move(res);
    }

    void DFS(TreeNode *node, int l)
    {
        if (node)
        {
            if (levelSum.size() < l + 1)
            {
                levelSum.push_back(node->val);
                levelCount.push_back(1);
            }
            else
            {
                levelSum[l] += node->val;
                ++levelCount[l];
            }
            DFS(node->left, l + 1);
            DFS(node->right, l + 1);
        }
    }
};