/*
 * @Author: SourDumplings
 * @Date: 2021-01-10 11:05:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
private:
    int count = 0;
    int res = 0;
    
    void in_order(TreeNode *node, int k)
    {
        if (node)
        {
            in_order(node->left, k);
            ++count;
            if (count == k)
            {
                res = node->val;
                return;
            }
            in_order(node->right, k);
        }
    }
public:
    int kthSmallest(TreeNode *root, int k)
    {
        in_order(root, k);
        return res;
    }
};