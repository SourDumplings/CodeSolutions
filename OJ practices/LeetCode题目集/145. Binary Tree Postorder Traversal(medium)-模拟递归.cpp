/*
 * @Author: SourDumplings
 * @Date: 2020-11-03 10:30:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 */

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        deque<int> temp;
        deque<TreeNode*> dq;
        if (root != nullptr)
        {
            dq.push_back(root);
        }
        while (!dq.empty())
        {
            TreeNode *p = dq.front();
            dq.pop_front();
            temp.push_front(p->val);
            if (p->left)
            {
                dq.push_front(p->left);
            }
            if (p->right)
            {
                dq.push_front(p->right);
            }
        }
        vector<int> res(temp.begin(), temp.end());
        return res;
    }
};