/*
 * @Author: SourDumplings
 * @Date: 2019-09-28 07:59:20
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-mode-in-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * BST的中序遍历肯定是有序的，相当于在有序序列中找众数了
 */
class Solution
{
private:
    int lastVal = -1, count = 0;
    bool isFirst = true;
    int maxCount = -1;

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        if (root)
        {
            inOrder(root, res);
            if (count > maxCount)
            {
                res.clear();
                res.push_back(lastVal);
                maxCount = count;
            }
            else if (count == maxCount)
            {
                res.push_back(lastVal);
            }
        }
        return res;
    }

    void inOrder(TreeNode *root, vector<int> &res)
    {
        if (root->left)
        {
            inOrder(root->left, res);
        }

        if (isFirst)
        {
            isFirst = false;
            lastVal = root->val;
        }

        if (root->val != lastVal)
        {
            if (count > maxCount)
            {
                res.clear();
                res.push_back(lastVal);
                maxCount = count;
            }
            else if (count == maxCount)
            {
                res.push_back(lastVal);
            }

            count = 1;
            lastVal = root->val;
        }
        else
        {
            ++count;
        }

        if (root->right)
        {
            inOrder(root->right, res);
        }
    }
};