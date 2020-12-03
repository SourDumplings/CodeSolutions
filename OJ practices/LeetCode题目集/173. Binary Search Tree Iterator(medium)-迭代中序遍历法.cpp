/*
 * @Author: SourDumplings
 * @Date: 2020-12-03 11:02:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-search-tree-iterator/
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
class BSTIterator
{
private:
    stack<TreeNode *> S;

    void _left_most_in_stack(TreeNode *node)
    {
        while (node)
        {
            S.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode *root)
    {
        _left_most_in_stack(root);
    }

    int next()
    {
        TreeNode *leftMost = S.top();
        S.pop();
        if (leftMost->right)
        {
            _left_most_in_stack(leftMost->right);
        }
        return leftMost->val;
    }

    bool hasNext()
    {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */