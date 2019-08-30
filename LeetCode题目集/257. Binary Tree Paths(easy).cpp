/*
 * @Author: SourDumplings
 * @Date: 2019-08-30 19:49:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> res;
        if (!root)
        {
            return res;
        }

        dfs(root, path, res);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &path, vector<string> &res)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            record(path, res);
        }

        if (root->left)
        {
            dfs(root->left, path, res);
        }
        if (root->right)
        {
            dfs(root->right, path, res);
        }
        path.pop_back();
    }

    void record(vector<int> &path, vector<string> &res)
    {
        string temp;
        int output = 0;
        for (auto &&i : path)
        {
            if (output++)
            {
                temp += "->";
            }
            temp += to_string(i);
        }
        res.push_back(temp);
    }
};