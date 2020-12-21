/*
 * @Author: SourDumplings
 * @Date: 2020-12-21 08:05:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-right-side-view/
 */

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> q;
        if (!root)
        {
            return res;
        }
        q.push(root);
        while (!q.empty())
        {
            queue<TreeNode *> thisLevel;
            while (!q.empty())
            {
                TreeNode *node = q.front();
                thisLevel.push(node);
                q.pop();
                if (q.empty())
                {
                    res.push_back(node->val);
                }
            }
            while (!thisLevel.empty())
            {
                TreeNode *node = thisLevel.front();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                thisLevel.pop();
            }
        }
        return res;
    }
};