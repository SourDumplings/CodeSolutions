/*
 * @Author: SourDumplings
 * @Date: 2021-01-05 18:44:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/count-complete-tree-nodes/
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
    int res = 0;
    
    void pre_order(TreeNode *node)
    {
        if (node)
        {
            ++res;
            pre_order(node->left);
            pre_order(node->right);
        }
    }
public:
    int countNodes(TreeNode *root)
    {
        pre_order(root);
        return res;
    }
};