/*
 * @Author: SourDumplings
 * @Date: 2019-10-07 10:31:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        if (root)
        {
            doPostOrder(root, res);
        }
        return res;
    }

    void doPostOrder(Node *root, vector<int> &res)
    {
        for (auto &&c : root->children)
        {
            if (c)
            {
                doPostOrder(c, res);
            }
        }
        res.push_back(root->val);
    }
};