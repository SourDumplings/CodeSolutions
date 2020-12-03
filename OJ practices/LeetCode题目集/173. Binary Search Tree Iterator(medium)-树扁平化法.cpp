/*
 * @Author: SourDumplings
 * @Date: 2020-12-03 09:54:08
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
    vector<int> vals;
    int index;

    void _in_order(TreeNode *node)
    {
        if (node)
        {
            _in_order(node->left);
            vals.push_back(node->val);
            _in_order(node->right);
        }
    }
public:
    BSTIterator(TreeNode *root): index(-1)
    {
        _in_order(root);
    }

    int next()
    {
        return vals[++index];
    }

    bool hasNext()
    {
        return index < static_cast<int>(vals.size()) - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */